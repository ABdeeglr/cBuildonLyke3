#include<stdio.h>
// C 中的switch语句是一个跳转表，switch接受的表达式的结果必须是整数，这些整数用于计算从switch顶部到匹配部分的跳转。
// C 我讨厌switch

int main(int argc, char const *argv[])
{
    if(argc != 2){
        printf("ERROR: You need one argument.\n");
        // this is how you abort a program.
        return 1;
    }

    int i = 0;
    for(i = 0; argv[1][i] != '\0'; i++){
        char letter = argv[1][i];

        switch (letter)
        {
        case 'A':
        case 'a':
            printf("%d: 'A'\n", i);
            break;

        case 'E':
        case 'e':
            printf("%d: 'E'\n", i);
            break;

        case 'I':
        case 'i':
            printf("%d: 'I'\n", i);
            break;

        case 'O':
        case 'o':
            printf("%d: 'O'\n", i);
            break;

        case 'U':
        case 'u':
            printf("%d: 'U'\n", i);
            break;

        case 'Y':
        case 'y':
            printf("%d: 'Y'\n", i);
            break;
        
        default:
            printf("%d: %c is not a vowel\n", i, letter);
        }
    }
    
    return 0;
}
