/*
 * @file : ex18.c | Exercise 18: Pointers to Functions
 * Author: ABdeeglr <abdeeglr@icloud.com>
 * Date  : 2023.2.28
 * Usage : 展示一个指向函数的指针 
 * Result: 
 *
 * New Concepts:
 * 	1) typedef int (*compare_cb)(int a, int b)
 * 	2)
 *
 * Include Function:
 *	1) int main |
 *  	2) void die() |
 *     	3) int* bubble_sort() |
 *     	4) void test_sorting() |
 *     	5) int sort_order() |
 *     	6) int reverse_order() |
 *     	7) int strange_order()
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_cb)(int a, int b);

/**
 * A classic bubble sort function that uses the
 * compare_cb to do the sorting.
 */

int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if(!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    for(i = 0; i < count; i++) {
        for(j = 0; j < count - 1; j++) {
            if(cmp(target[j], target[j+1]) > 0) {
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }

    return target;
}


int sorted_order(int a, int b){
	return a - b;
}


int reverse_order(int a, int b){
	return b - a;
}


int strange_order(int a, int b){
	if (a == 0 || b == 0){
		return 0;
	}
	else {
		return a % b;
	}
}


/*
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */


void test_sorting(int *numbers, int count, compare_cb cmp){
	int i = 0;
	int* sorted = bubble_sort(numbers, count, cmp);

	if (!sorted) die("Failed to sort as requested!\n");

	for (i = 0; i < count; i++){
		printf("%d ", sorted[i]);
	} printf("\n");

	free(sorted);
}


int main(int argc, const char* argv[]){
	
	if (argc < 2) die("USAGE not qualifed.");
	int count = argc - 1;
	int i = 0;
	char **inputs = argv + 1;

	int *numbers = malloc(count * sizeof(int));
	if (!numbers) die("Memory out!\n");

	for (i = 0; i < count; i++){
		numbers[i] = atoi(inputs[i]);
	}

	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, reverse_order);
	test_sorting(numbers, count, strange_order);

	free(numbers);

	return 0;
}


/*
 * @log:./ex18 3 33 3333 9 21 42 23
3 9 21 23 33 42 3333 
3333 42 33 23 21 9 3 
3333 33 9 42 21 3 23 
*/


