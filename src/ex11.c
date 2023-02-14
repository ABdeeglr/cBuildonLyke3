#include <stdio.h>
// 这个代码的含义并不困难，但是我很想知道如何把任意数量的元素都塞进预先声明的数组里面去
int main(int argc, char const *argv[])
{
    int i = 0;
    while(i < argc){
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    char* states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;
    i = 0;
    while(i < num_states){
        printf("state %d: %s\n", i, states[i]);
        i++;
    }

    return 0;
}
