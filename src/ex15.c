#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// utt() is a function for test pointers' addition
int utt();
// utt2() is a function for test string pointer's size
int utt2();


//ex15.c src-code superessed here | Exercise 15: Pointers Dreaded Pointers
int ex15();
//ex16.c src-code superessed here | Exercise 16: Structs and Pointers to Them
int ex16();
//ex16.c src-code superessed here | Exercise 17: Heap and Stack Memory Allocation
int ex17();
//ex16.c src-code superessed here | Exercise 18: Pointers to Functions
int ex18();


int main(int argc, char const *argv[])
{
    // ex15();
    ex16();
    
    
    // utt();
    // utt2();

    return 0;
}


int ex15()
{
// create two arrays we care about
    printf("----- Test 1 -----\n");
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frankjnbubninknknnkn", "Marry",
        "John", "Lisa"
    }; // I need to know whether it's an array of pointers or an pointer to char array

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;
    
    for (i = count - 1; i >= 0; i -= 1)
    {
        printf("%s has %d years alive. <%lu>\n",
               names[i], ages[i], sizeof(names[i]));
    }

    printf("\n----- Test 2 -----\n");

    // setup the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;

    // second way using pointers
    for (i = count - 1; i >= 0; i -= 1)
    {
        printf("%s (at <%p>) is %d (at <%p>) years old.\n",
               *(cur_name + i), cur_name + i, *(cur_age + i), cur_age + i);
    }

    printf("\n----- Test 3 -----\n");
    
    // third way, pointers are just arrays
    for(i = count - 1; i >= 0; i -= 1)
    {
        printf("%s (at <%p>) is %d (at <%p>) years old again.\n",
               cur_name[i], &cur_name[i], cur_age[i], &cur_age[i]);
    }


    printf("\n----- Test 4 -----\n");

    // forth way with pointers in a stupid complex way
    for(cur_name = names + count - 1, cur_age = ages + count - 1;
        (cur_age - ages) >= 0;
        cur_name--, cur_age--)
        {
            printf("%s (at <%p>) lived %d (at <%p>) years so far. \n",
                   *cur_name ,cur_name ,*cur_age, cur_age);
        }
    
    return 0;
}


int ex16()
{
    struct Person{
        char *name;
        int age;
        int height;
        int weight;
    };

    struct Person *Person_create(char *name, int age, int height, int weight)
    {
        struct Person *who = malloc(sizeof(struct Person));
        assert(who != NULL);

        who -> name = strdup(name);
        who -> age = age;
        who -> height = height;
        who -> weight = weight;

        return who;
    }


    return 0;
}


int ex17()
{
    return 0;
}


int ex18()
{
    return 0;
}


int utt()
{
    long int a[4] = {11,12,13,14};
    long int *p = a;

    int i = 0;
    for(i = 0; i < 4; i++)
    {
        printf("At address: %p, and its value is %ld.\n", p + i, *(p + i));
    }

    return 0;
}


int utt2()
{
    char *p = "SSVFD";
    char *pc[] = {
        "asdde", "qwdrefde", "dwefr"
    };

    printf("<%p> | %lu \n", p, sizeof(p));

    int i = 0;
    for(i = 0; i < 3; i++)
    {
        printf("<%p> | %lu \n", pc[i], sizeof(pc[i]));
    }
    
    return 0;
}
