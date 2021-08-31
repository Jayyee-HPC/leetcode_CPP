/**
 * @file     selection_sort.cpp
 */
/* Author J.Y. */

/** Selection sort
 * The selection sort algorithm sorts an array by repeatedly finding the minimum element 
 * from unsorted part and putting it at the beginning.
 * The algorithm maintains two subarrays in a given array.
 * 1. The subarray which is already sorted. 
 * 2. Remaining subarray which is unsorted.
 */

//g++ -std=c++11 -o prog selection_sort.cpp

#include <stdio.h>
#include <cstddef>
#include <iostream>
#include <chrono>       /* std::chrono::seconds, std::chrono::milliseconds */
#include <stdlib.h>     /* srand, rand */
#include <cstring>      /* memcpy */
#include <cassert>      /* assert */


#define TEST_RANDOM_SEED 1234567

void selection_sort(int arr[], size_t size);
void swap(int &val_1, int &val_2);
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

void swap(int *val_1, int *val_2)
{
    int temp_val = *val_1;
    *val_1 = *val_2;
    *val_2 = temp_val;
}

void selection_sort(int *arr, size_t size)
{
    if (arr == NULL)return;

    for (size_t i = 0; i < size; ++i)
    {
        size_t min_index = i;

        for (size_t j = i+1; j < size; ++j)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        swap(&arr[i], &arr[min_index]);
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

    selection_sort(arr, 1000);

    for (size_t i = 1; i < 1000; ++i)
    {
        assert(arr[i] >= arr[i-1]);
    }
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

    selection_sort(arr, 10000);

    for (size_t i = 1; i < 1000; ++i)
    {
        assert(arr[i] >= arr[i-1]);
    }
}



