#include <stdio.h>
#include <string.h>

// 这些内容取自"C primer plus"-p80-p88 

/* Conversion Specification
 * %a/%A 浮点数，十六进制数和p计数法
 * %c 单个字符
 * %d 有符号十进制整数
 * %e/%E 浮点数, e计数法
 * %f 浮点数标准输出
 * %g/%G 不常用，用于表示浮点数
 * %i 有符号十进制整数
 * %o 无符号八进制整数
 * %p 指针
 * %s 字符串
 * %u 无符号十进制整数
 * %x 无符号十六进制整数
 * %% 打印一个百分号
 */ 


// 测试浮点数的p计数法和e计数法打印方式
// 112358.140625 标准输出
// 0x1.b6e624p+16 0x表示16进制输出，p+16表示乘以2^16
// 1.123581e+05 科学计数法输出，e+05表示乘以10^5
int test_for_p_and_e();


// 使用转换说明
int printout();

//Conversion Specification的修饰符
// %d 这样的内容被称为格式化字符串的转换说明，这些转换说明中还能够插入额外的修饰符
// 下面的函数就是对这些修饰符的示范
int conversion_specification();


// 这是一个练习
int exercise();

// 关于转换说明的根本机制解释
int intconv();


// 一个简单的二进制数转换,将64位以下的十进制正整数转化为二进制形式
// 下一步希望以字符串形式输出
char *bintransfer(int num);


// 正整数指数幂计算器
int power(int num, int power);


// 将一个字符串逆序输出.
// 这个函数还没有完成
char *str_reverse(char *input_str);




int main(int argc, char const *argv[])
{
    // test_for_p_and_e();
    // conversion_specification();
    // exercise();

    intconv();

       

    return 0;
}




int test_for_p_and_e(){

    float num = 112358.1415926;

    printf("Type %%f: >> %f <<\n", num); // 112358.140625 标准输出
    printf("Type %%a: >> %a <<\n", num); // 0x1.b6e624p+16 0x表示16进制输出，p+16表示乘以2^16
    printf("Type %%e: >> %e <<\n", num); // 1.123581e+05 科学计数法输出，e+05表示乘以10^5

    float a = 3.1415926;
    double b = 3.1415925;

    printf("This is double: >> %f << size of double:%lu\n", b, sizeof b); // double的size是64位
    printf("This is float: >> %f << size of float:%lu\n", a, sizeof a); // float的size是32位

    return 0;
}


int printout(){

    float pies = 12.75;
    int num = 7;
    float pi = 3.14159;
    int cost = 7800;
    
    // 不用练习了，我已经搞明白了

    return 0;
}


int conversion_specification(){

    printf("----- Integer Conversion -----\n");
    int pages = 959;
    printf(">> %d <<\n", pages);
    printf(">> %2d <<\n", pages);
    printf(">> %10d <<\n", pages);
    printf(">> %-10d <<\n", pages);

    /* OUTPUT DETAIL
    >> 959 <<
    >> 959 <<
    >>        959 <<
    >> 959        <<
    */

    printf("----- Float Conversion -----\n");
    double rent = 3852.99;
    printf(">> %f <<\n", rent);
    printf(">> %e <<\n", rent);
    printf(">> %4.2f <<\n", rent);
    printf(">> %3.1f <<\n", rent);
    printf(">> %10.3f <<\n", rent);
    printf(">> %10.3E <<\n", rent);
    printf(">> %+4.2f <<\n", rent);
    printf(">> %010.2f <<\n", rent);

    /* OUTPUT DETAIL
    >> 3852.990000 <<
    >> 3.852990e+03 <<
    >> 3852.99 <<
    >> 3853.0 <<
    >>   3852.990 <<
    >>  3.853E+03 <<
    >> +3852.99 <<
    >> 0003852.99 <<
    */

    printf("----- yue! 这啥啊 -----\n");
    printf("%x %X %#x\n", 31, 31, 31);
    printf("**%d**% d**%  d**\n", 42, 42, -42);
    printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);

    /* OUTPUT DETAIL
    1f 1F 0x1f
    **42** 42**-42**
    **    6**  006**00006**  006**
    */

    char str[] = "United States";
    printf("----- 字符串输出转换演示 -----\n");
    printf("[%2s]\n", str);
    printf("[%24s]\n", str);
    printf("[%24.5s]\n", str);
    printf("[%-24.5s]\n", str);

    /* OUTPUT DETAIL
    [United States]
    [           United States]
    [                   Unite]
    [Unite                   ]
    */



    return 0;
}


int exercise(){
    char name[] = "Genshin";
    float cash = 114514.1919810;

    printf("The %s family just may be $%.2f dollars richer!\n", name, cash);

    return 0;
}


int intconv(){
    // 下面的循环表明，如果要将一个有符号整型输出为无符号整型，那么在有限的正值范围内是相同的，这个范围取决于该整型的大小，通常在2^15 或 2^7 以内。如果超出了这个范围，则无符号整型对应的整型变为负数，并满足 2^15(2^7) 等于被强制转换的负数的绝对值加上无符号整数的值。
    int i = 0;
    while(i < 100000){
        printf("2^sizeof(int)(%lu) = - (%%d:%d) + %%u:%u.\n",sizeof(int), -i, -i);

        i += 1024;
    }

    // 另外，使用%c转换超出8位的数据时, 只取后8位, 因此 336 被强制转换后显示为’P‘.

}


char *bintransfer(int num){
    int num_using = num;
    if (num_using <= 0){
        printf("This is not a qualified number.");
        return "False";
    }
    else{
        short i = 0;
        char bin_num[64];
        while (num_using > 0){
            int res = num_using % 2;
            bin_num[i] = res + 48;
            i += 1;
            num_using = (num_using - res) / 2;
        }
        bin_num[i] = '\0';
        int bin_num_len = strlen(bin_num);
        printf("%d ==> ", num);
        while(bin_num_len > 0){
            printf("%c", bin_num[bin_num_len - 1]);
            bin_num_len -= 1;
        }
        printf(".\n");
    }

    return "Unifished";
}



char *str_reverse(char *input_str){
    char res[64];
    int _strlen = strlen(input_str);

    return "Unifishede Function";
}



int power(int num, int power){

    int res = 1;
    while(power > 0){
        res *= num;
        power -= 1;
    }

    return res;
}