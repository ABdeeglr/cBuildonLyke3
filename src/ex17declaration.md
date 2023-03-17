# EX17 说明



## 大纲

**常量声明**

1. DATA_MAX
2. DATA_ROWS

**结构**

1. Address
2. Database
3. Connection

**方法**

1. Address_print(struct Address*)
2. Database_load(struct Connection*)
3. Database_open(struct) 未知
4. Database_write(struct Connection*)
5. Database_create(struct Connection*)
6. Database_delete(struct Connection*)
7. Database_set(struct Connection*)
8. Database_get(struct Connection*)
9. Database_list(struct Connection*)
10. die(const char*)



## 分而治之

### FILE 类及其方法

**fopen函数**

```c
FILE *fopen(const char *filename, const char *mode)
```

| 模式 |                             描述                             |
| :--- | :----------------------------------------------------------: |
| "r"  |           打开一个用于读取的文件。该文件必须存在。           |
| "w"  | 创建一个用于写入的空文件。如果文件名称与已存在的文件相同，则会删除已有文件的内容，文件被视为一个新的空文件。 |
| "a"  | 追加到一个文件。写操作向文件末尾追加数据。如果文件不存在，则创建文件。 |
| "r+" |   打开一个用于更新的文件，可读取也可写入。该文件必须存在。   |
| "w+" |                  创建一个用于读写的空文件。                  |
| "a+" |                打开一个用于读取和追加的文件。                |

**fclose函数**

```c
int fclose(FILE *stream)
```

关闭流，刷新缓冲区，如果成功则返回0, 不成功返回 EOF

**fread函数**

```c
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
```

示例

```c
#include <stdio.h>
#include <string.h>
 
int main()
{
   FILE *fp;
   char c[] = "This is runoob";
   char buffer[20];
 
   /* 打开文件用于读写 */
   fp = fopen("file.txt", "w+");
 
   /* 写入数据到文件 */
   fwrite(c, strlen(c) + 1, 1, fp);
 
   /* 查找文件的开头 */
   fseek(fp, 0, SEEK_SET);
 
   /* 读取并显示数据 */
   fread(buffer, strlen(c)+1, 1, fp);
   printf("%s\n", buffer);
   fclose(fp);
   
   return(0);
}
```



**rewind函数**

```c
void rewind(FILE *stream)
```

C 库函数 void rewind(FILE \*stream) 设置文件位置为给定流 stream 的文件的开头.

### 字符输入与输出

#### 01 输入形式

输入是一种抽象，称为 Stream，键盘输入、鼠标移动，都是一个输入流。对于这样的输入，有两类方式进行回应。

一类是无缓冲输入，比如移动鼠标发出向上或向下的信号，程序立刻接收该信号作出回应。无缓冲输入是即时交互需求的产物。

另一类是缓冲输入，可以分为完全缓冲和行缓冲。缓冲输入时，信号串首先发送到缓冲区，缓冲区刷新和信号串发送到程序的行为似乎有深度联系。

完全缓冲在缓冲区被填满时将用户输入交给程序，因此缓冲区的大小决定了缓冲区刷新时机，这种方式似乎并不常见。行缓冲在用户输入回车时刷新缓冲区，这在使用命令行与计算机交互时常见。

#### 02 文件读写的函数

文件需要被读写。直接调用系统底层的函数被称为底层I/O, 但这些函数在不同的操作系统上并不一致。ANSI C 提供了标准 I/O 包，从而处理不同系统的差异。

差异是指不同的操作系统以不同的方式储存文件，因此同样的读写操作在不同的操作系统上会遇到异常。



**Stream结束标记**

EOF 是一个特殊的值，用于标记读取 Stream 内容的结束。

**重定向输入和重定向输出**

使用 `>` 和 `<` 可以对输入和输出进行重定向。

#### 03 流 stream

前面说的输入是一种抽象，其名为 Stream, 对于文件读写，系统也认为这是一个流。流的结尾以特殊字符标注，从而标记文件结尾。现代操作系统通过文件大小来确定文件的结尾。当读取到文件末尾时，获取输入的函数便返回一个 EOF(End of file) 值，通常为 -1.



## die函数

`void die(const char* message)` 是基于 stdio.h 和 errno.h 创建的函数, 用于捕捉错误.