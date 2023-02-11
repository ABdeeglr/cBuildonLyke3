#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#define DENSITY 62.4
#define PRAISE "You are an extraordinary being."
#define PI 3.14159


int talkback(){
    float weight, volume;
    int size, letters;
    char name[40];

    printf("Hi! What's your first name?\n");
    scanf("%s", name); // They are both address, why different?
    printf("%s, what's your weight in pounds?\n", name);
    scanf("%f", &weight); // They are both address, why different?
    size = sizeof(name);
    letters = strlen(name);
    volume = weight / DENSITY;
    printf("Well, %s, your volume is %2.2f cubic feet.\n", name, volume); // %m.nf "m" means length of output, "n" means 0.xxxx(n * x), for example %.3f -> 0.123, %.8f -> 0.12340000
    printf("Also, your first name has %d letters,\n", letters);
    printf("and we haave %d bytes to store it.\n", size);

    return 0;
}

// Here you can give a declaration for function.
int praise1(){
    char name[40];

    printf("What's your name? ");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);

    return 0;
}

char *praise2(){
    char name[40];

    printf("What's your name? ");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    printf("Your name of %lu letters occupies %lu memory cells.\n",
        strlen(name), sizeof(name));
    printf("The phrase of praise has %lu letters ", strlen(PRAISE));
    printf("and occupies %lu memory cells.\n", sizeof(PRAISE));

    return "Nm$L";
}


int pizza(){
    float area, circum, radius;

    printf("What is the radius of your pizza?\n");
    scanf("%f", &radius);
    area = PI * radius * radius;
    circum = 2.0 * PI * radius;
    printf("Your basic pizza parameters are as follows:\n");
    printf("circumference = %1.2f, area = %1.2f\n", circum, area);

    return 0;
}


int defines(){

    printf("Some number limits for this system:\n");
    printf("Biggest int: %d", INT_MAX);
    printf("Smallest long long: %lld\n", LLONG_MIN);
    printf("One byte = %d bits on this machine.\n", CHAR_BIT);
    printf("Largest double: %e\n", DBL_MAX);
    printf("Smallest normal float: %e\n", FLT_MIN);
    printf("float precision = %d digits\n", FLT_DIG);
    printf("float epsilon = %e\n", FLT_EPSILON);

    return 0;
}


int main(int argc, char const *argv[])
{   
    /*
     * talkback();
     * praise1();
     * praise2();
     * pizza();
     */
    defines();
    
    
    return 0;
}
