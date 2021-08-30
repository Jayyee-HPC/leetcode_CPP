/**
 * @file     insertion_sort.cpp
 */
/* Author J.Y. */

/** Insertion sort
 * 1. Iterate from arr[1] to arr[n-1].
 * 2. Compare the current element (key) to its predecessor
 * 3. If the key is smaller than its predecessor, compare it to the elements before.
 *    Move the greater elements one position up to make space for the swapped element.
 */

//g++ -std=c++11 -o prog insertion_sort.cpp

#include <stdio.h>
#include <cstddef>
#include <iostream>
#include <chrono>       /* std::chrono::seconds, std::chrono::milliseconds */
#include <stdlib.h>     /* srand, rand */


#define TEST_RANDOM_SEED 1234567

void insertion_sort(int arr[], size_t size);
void testcase_1(void);
void testcase_2(void);

int main(int argc, char* *argv)
{
    double t_test_1, t_test_2;
    t_test_1 = t_test_2 = 0.0;

    auto t_begin = std::chrono::steady_clock::now();
    testcase_1();
    auto t_test1_end = std::chrono::steady_clock::now();
    testcase_2();
    auto t_test2_end = std::chrono::steady_clock::now();

    std::chrono::duration<double> t_diff_temp = t_test1_end - t_begin;
    t_test_1 = t_diff_temp.count();

    t_diff_temp = t_test2_end - t_test1_end;
    t_test_2 = t_diff_temp.count();

    std::cout<<"Test 1 finished in "<<t_test_1<<" seconds"<<std::endl;
    std::cout<<"Test 2 finished in "<<t_test_2<<" seconds"<<std::endl;
}

void insertion_sort(int *arr, size_t size)
{
    if (arr == NULL)return;

    for (size_t i = 1; i < size; ++i)
    {
        int key = arr[i];
        size_t pos = i - 1;

        while (pos >= 0 && arr[pos] > key)
        {
            arr[pos+1] = arr[pos];
            pos = pos - 1;
        }

        arr[pos+1] = key;
    }
}

void testcase_1(void)
{
    int *arr;

    arr = (int *)malloc(sizeof(int) * 1000);

    srand(TEST_RANDOM_SEED);
    for (size_t i = 0; i < 1000; ++i)
    {
        arr[i] = rand() % 10000 + 1;
    }

    insertion_sort(arr, 1000);
}

void testcase_2(void)
{
    int *arr;

    arr = (int *)malloc(sizeof(int) * 10000);

    srand(TEST_RANDOM_SEED);
    for (size_t i = 0; i < 10000; ++i)
    {
        arr[i] = rand() % 100000 + 1;
    }

    insertion_sort(arr, 10000);
}



