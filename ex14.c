#include <stdio.h>
#include <ctype.h>

int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[])
{
    int i = 0;

    for(i = 0; i < argc; i++) {
        print_letters(argv[i]);
    }
}

void print_letters(char arg[])
{
    int i = 0;

    for(i = 0; arg[i] != '\0'; i++) {
        char ch = arg[i];

        if(can_print_it(ch)) {
            printf("'%c' == %d ", ch, ch);
        }
    }

    printf("\n");
}

int can_print_it(char ch)
{
    return isalpha(ch) || isblank(ch);
}


int main(int argc, char const *argv[])
{
    char lst[] = {
        '3','a','\0','x','e'
    };

    int length = sizeof(lst) / sizeof(char);
    int i;
    for (i = 0; i < length; i++){
        printf("%c means %d.\n", lst[i], can_print_it(lst[i]));
    }
    
    return 0;
}
