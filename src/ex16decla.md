# EX16 的结构体指针说明



## 01 四个库文件

**stdio.h**

一个标准的输入输入库，用于调用系统进行输出。源代码中使用的函数为 printf() 函数。

**assert.h**

源代码中使用了该库中的 asse可以是rt() 函数。该函数是该库中唯一定义的函数。assert() 函数接受一个表达式，例如

```c
assert(who != NULL)
```

如果该表达式的值为 0(False)，则终止程序运行并报告。

在上述例子中， `who != NULL` 用于判断该指针是否为空。如果该指针为空，则中断程序。反之则继续程序。从这里可以得到一个判断，即 assert 通常用于检验某个程序错误，如果该程序错误确实发生，则报告。在上述例子中，需要检测的错误是指针为空，其表达式为 `who == NULL` ，使 assert 函数报告该错误的方式就是将等于判断改为不等于判断。

更具与可读性的写法可以是

```c
assert(!(who == NULL))
```

**string.h**

该库主要由操控字符串的函数组成。在源代码中使用的是 NULL，这是一个 空指针常量的值。

源代码中使用了该库中的 strdup 函数函数. 但我目前还没有搞清楚 strdup 究竟作了什么, 即使它解决了字符串从函数的 local namespace 中传出的问题.



**stdlib.h**

该库主要由 5 个宏和 29 个函数组成. 与 string.h 一样定义了宏变量 NULL.

在源代码中主要使用了其关于内存管理的几个函数：

1. void *malloc()
2. void free(void *pointer)

malloc 函数接受一个无符号整型, 通常与 sizeof() 函数一起使用, 用于接受 sizeof 函数返回的内存大小, 单位为字节.



free 函数接收一个指针, 释放该指针占据的内存块.



## 02 结构体

**结构体声明**

对应源代码中的

```c
struct Person{
    char* name;
	...;
	...;
	...;
}
```

该声明确定了这个结构体的名词, 具有哪几个属性.

**结构体实现**

类似于 python 中的 init 函数, 不过需要手动定义.

```c
struct Person *Person_create(char *name, int age, int height, int weight){
    struct Person *who = malloc(sizeof(struct Person));
    assert(!(who == NULL));

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}
```

第一行声明了结构体的 init 函数, 这个函数称为 Person_create, 接收四个参数, 并返回一个 struct Person 类型的指针. 

第二行向内存申请空间, 通过 malloc 函数实现, 从而创造了一个名为 who 的 struct Person 指针.

第三到第八行, 通过 assert 函数确保 who 不是一个空指针, 并对其属性进行赋值. `who->attribute` 的语法等同于 `(*who).attribute` . 其中, 第五行由于复制对象是字符串指针变量, 因此需要 strdup 函数进行分配内存地址从而确保复制是"永久"的.

第十行返回 who 的指针地址.



**销毁**

Person_destory 函数在某个结构体实例的生命周期完成时进行销毁, 释放内存空间. 它接收 struct Person 类型的指针, 并销毁指针.



**结构体方法**

Person_print 是定义在 struct Person 类型上的一个函数, 因此是方法. 本质上和 python 中的定义没有区别.





## 附加题

在这个练习的附加题中我想让你尝试一些有难度的东西：将这个程序改为不用指针和`malloc`的版本。这可能很困难，所以你需要研究下面这些东西：

- 如何在栈上创建结构体，就像你创建任何其它变量那样。
- 如何使用`x.y`而不是`x->y`来初始化结构体。
- 如何不使用指针来将结构体传给其它函数。



根本无法理解! 究竟还有什么方式能够分配内存?? 我缺少了某一个基础知识, 导致我对这个问题无法进行有目的性的思考, 暂时放弃.