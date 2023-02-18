// Exercise 16: Structs and Pointers to Them
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>


struct Person {
    char *name;
    int age;
    int height;
    int weight;
};


struct Person *Person_create(char *name, int age, int height, int weight){
    struct Person *who = malloc(sizeof(struct Person));
    assert(!(who == NULL));

    (*who).name = strdup(name);
    (*who).age = age;
    (*who).height = height;
    (*who).weight = weight;

    return who;
}


void Person_destory(struct Person *who){
    assert(who != NULL);

    free(who->name);
    free(who);
}


void Person_print(struct Person *who){
    printf("Name: %s\n", (*who).name);
    printf("\tAge: %d\n", (*who).age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}


char *getname(){
    char *name = "Test it";

    return strdup(name);
}

int main(int argc, char const *argv[]){

    struct Person *joe = Person_create(
        "Joe Alex", 32, 64, 140);

    struct Person *frank = Person_create(
        "Frank Mini", 20, 50, 150);

    printf("Joe is at mermory location %p: Size: %lu\n", joe, sizeof(joe));
    Person_print(joe);
    printf("Frank is at mermory location %p: Size: %lu\n", frank, sizeof(frank));
    Person_print(frank);
    // printf("Size of struct Person: %lu\n", sizeof(struct Person));

    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);
    
    (*frank).age += 20;
    (*frank).weight += 20;
    Person_print(frank);

    Person_destory(joe);
    Person_destory(frank);

    // char *name = getname();

    // printf("%s\n", name);


    
    return 0;
}

