#include <stdio.h>

int main(int argc, char *argv[])
{
    // go through each string in argv

    int i = 1;
    while(i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    // let's make our own array of strings
    char *states[4];

    int num_states = 4;
    i = 1;  // watch for this
    while(i < num_states+1) {
        states[i-1] = argv[i];
        i++;
    }

    for(i = 0; i < num_states; ++i){
        printf("States[%d] >> %s.\n", i, states[i]);
    }

    return 0;
}