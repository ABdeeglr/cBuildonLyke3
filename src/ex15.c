// Exercise 15: Pointers Dreaded Pointers
#include<stdio.h>

int main(int argc, char const *argv[])
{
    // create two arrays we care about
    printf("----- Test 1 -----\n");
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frank", "Marry", "John", "Lisa"
    }; // I need to know whether it's an array of pointers or an pointer to char array

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;
    
    for (i = 0; i < count; i += 1){
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }

    printf("\n----- Test 2 -----\n");

    // setup the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;

    // second way using pointers
    for (i = 0; i < count; i += 1){
        printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
    }

    printf("\n----- Test 3 -----\n");
    
    // third way, pointers are just arrays
    for(i = 0; i < count; i += 1){
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }


    printf("\n----- Test 4 -----\n");

    // forth way with pointers in a stupid complex way
    for(cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++){
        printf("%s lived %d years so far.\n");
    }


    return 0;
}
