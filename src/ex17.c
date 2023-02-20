// Exercise 17: Heap and Stack Memory Allocation
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<errno.h>

#define MAX_DATA 512
#define MAX_ROWS 100


// 定义 3 个基本类
struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};


struct Database {
    struct Address rows[MAX_DATA];
};


struct Connection {
    FILE *file;
    struct Database *db;
};


// 用于处理用户错误操作，但我不知道为什么要写成这样
void die(const char *message){
    if(errno){
        perror(message);
    }
    else{
        printf("\ERRROR: %s\n", message);
    }

    exit(1);
}



// struct Address method: 打印 address 的具体内容
void Address_print(struct Address *addr){
    printf("%d %s %s\n",
        addr->id, addr->name, addr->email);
}

// struct Connection method: 暂时还搞不清楚他的含义
void Database_load(struct Connection *conn){
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1){
        die("Failed to load databese.");
    }
}


// struct Connection method: 释放db,conn,file占据的内存
void Database_close(struct Connection *conn)
{
    if(conn) {
        if(conn->file) fclose(conn->file); // close the file
        if(conn->db) free(conn->db); // free pointer to db
        free(conn); // free pointer to connection
    }
}


// Function: 用于打开一个数据库，并返回一个连接
struct Connection *Database_open(const char *filename, char mode){
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) die("Memory error");

    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) die("Memory error");

    if(mode == 'c'){
        conn->file = fopen(filename, "w");
    }
    else{
        conn->file = fopen(filename, "r+");
        if(conn->file){
            Database_load(conn);
        }
    }

    if(!conn->file) die("Failed to open the file");

    return conn;
}

// struct Connection method: 
void Database_write(struct Connection *conn){
    rewind(conn->file); // stdio 成员函数，作用未知

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Failed to write database.");

    rc = fflush(conn->file);
    if(rc == -1) die("Cannot flush database.");
}

// struct Connection method: 
void Database_create(struct Connection *conn){
    int i = 0;

    for (i = 0; i < MAX_ROWS; i++){
        // make a prototype to initialize it
        struct Address addr = {.id = i, .set = 0};
        // then just assign it
        conn->db->rows[i] = addr;
    }
}


// struct Connection method: 
void Database_set(struct Connection *conn,
                int id, const char *name, 
                const char *email){
    struct Address *addr = &conn->db->rows[id];
    if (addr->set) die("Already set, delete it first");

    addr->set = 1;
    // WARNING: bug, read the "How to breakit" and fix this
    char *res = strncpy(addr->name, name, MAX_DATA); // string 标准库中的成员函数，意义未知
    // demonstrate the strncpy bug
    if (!res) die("Name copy failed");
    res = strncpy(addr->email, email, MAX_DATA);
    if (!res) die("Email copy failed");
}

// struct Connection method: 
void Database_get(struct Connection *conn, int id){
    struct Address *addr = &conn->db->rows[id];

    if (addr->set) {
        Address_print(addr);
    }
    else{
        die("ID is not set");
    }
}

// struct Connection method: 
void Database_delete(struct Connection *conn, int id){
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

// struct Connection method: 
void Database_list(struct Connection *conn){
    int i = 0;
    struct Database *db = conn->db;

    for (i = 0; i < MAX_ROWS; i++){
        struct Address *cur = &db->rows[i];

        if (cur->set) {
            Address_print(cur);
        }
    }
}



int main(int argc, char *argv[])
{
    if (argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);
    int id = 0;

    if (argc > 3) id = atoi(argv[3]); // 将输入的 id 转化为数字形式。 atoi 是 stdlib 中的函数, 将字符串形式的数字转化为整型，其他一律返回 0.
    if (id >= MAX_ROWS) die("There's not that many records.");

    switch (action)
    {
    case 'c':
        Database_create(conn);
        Database_write(conn);
        break;
    
    case 'g':
        if (argc != 4) die("Need an id to get");

        Database_get(conn, id);
        break;

    case 's':
        if (argc != 6) die("Need id, name, email to set");

        Database_set(conn, id, argv[4], argv[5]);
        Database_write(conn);
        break;

    case 'd':
        if (argc != 4) die("Need id to delete");
        
        Database_delete(conn, id);
        Database_write(conn);
        break;
    
    case 'l':
        Database_list(conn);
        break;
    
    default:
        die("Invaild action, only: c(=create)m g(=get), s(=set), d(=del, l=(list))");
    }
    
    Database_close(conn);

    return 0;
}
