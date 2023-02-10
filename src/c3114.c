#include<stdio.h>

int float_number_overflow_test(){
    float s = 3.14159;
    int i = 0;

    while (s > 0)
    {
        if (i < 30){
            i++;
        }
        else{
            break;
        }
        if (s * 100 > 0){
            s *= 100;
            printf("Now s is >> %e.\n", s);
            printf("The size of s is >> %ld.\n", sizeof(s));
        }
        else{
            printf("Float will overflow.\n");    
        };
    };

    return 0;
}

int type_test_int(){
    /*
     * It's a test for type int.
     * I want to know the size of "int/unsigned int/long int/long long int".
     * Besides I will test the use of %d/%ld/%ud/etc.
     */ 

    int a = 10000;
    long int b = 12000;
    long d = 1230000;
    long long int c = 3200000;

    printf("The size of int >> %lu.\n", sizeof(a));
    printf("The size of long int >> %lu.\n", sizeof(b));
    printf("The size of long long int >> %ld.\n", sizeof(c));
    printf("The size of long >> %ld\n", sizeof(d));

    /*
        Base with the test below, I now know that:
        1. use %lu or %ld to invoke long unsigned int numbers.
        2. the length of int is 32.
        3. the length of long/long int/long long int is 64.
    */

    int x = 1024;

    printf("dec = %d | oct = %o  | hex = %x.\n", x, x, x);
    printf("Dec = %d | Oct = %#o | Hex = %#x.\n",x ,x ,x);

    if (0x100 > 100){
        printf("True.\n");
        printf("Use 0{}- to enter hex number.\n");
    }
    else{
        printf("False.\n");
    }
    if (0100 < 100){
        printf("True.\n");
        printf("Use 0{} to enter hex number.\n");
    }
    else{
        printf("False.\n");
    }
    
    
    /*
        According to the test below. Now I give a suppose:
        1. The basic type is int.
        2. use long/unsigned to extend this basic type. Of course use %ld,%lu,%lld,%llu to show.
        3. use %o/%x to show oct and hex. Of course use %lo,%llu to show.

    */
    

    return 0;
}


int type_test_char(){
    char x = 'B';
    printf("Size of char >> %lu.\n", sizeof(x));

    // I get the size of char is 8 bits.
}

int type_test_float(){
    // It's a test for double/float/long duble:
    // 1. Declare the size of these type.
    // 2. Find how to use these numbers.

    float num1 = 1.667123134123123e-17;
    double num2 = 6.22312312412231e23;
    long double num3 = 9.219391288123123124e9;

    printf("num1 is >> %f.\n", num1);
    printf("num2 is >> %f.\n", num2);
    printf("num3 is >> %Lf.\n", num3);


    printf("The size of float is >> %lu.\n", sizeof (num1));
    printf("The size of double is >> %lu.\n", sizeof(num2));
    printf("The size of long double is >> %lu.\n", sizeof(num3));

    return 0;
}

int main(int argc, char const *argv[])
{   
    type_test_float();



    return 0;
}
