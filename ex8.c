#include<stdio.h>

int main(int argc, char const *argv[])
{
    int areas[] = {10,12,13,14,20};
    char name[] = "Zed";
    char full_name[] = {
        'Z','e','d',
        ' ','A','.',' ',
        'S','h','a','w','\0'
    };

    printf("The length of areas[] is %ld, because the size of int is %ld, and the size of areas[] is %ld.\n", sizeof(areas) / sizeof(int), sizeof(int), sizeof(areas));
    printf("The length of name[] is %ld, size of char >> %ld, and size of name[] is %ld.\n", sizeof(name) / sizeof(char), sizeof(char), sizeof(name));
    printf("The length of full_name[] is %ld.\n", sizeof(full_name) / sizeof(char));
    

    return 0;
}
