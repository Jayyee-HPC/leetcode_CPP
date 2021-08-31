/**
 * @file     quick_sort.cpp
 */
/* Author J.Y. */

/** Quick sort
 * QuickSort is a Divide and Conquer algorithm.
 * It picks an element as pivot and partitions the given array around the picked pivot.
 * elements if they are in wrong order.
 */

//g++ -std=c++11 -o prog quick_sort.cpp

#include <stdio.h>
#include <cstddef>
#include <iostream>
#include <chrono>       /* std::chrono::seconds, std::chrono::milliseconds */
#include <stdlib.h>     /* srand, rand */
#include <cstring>      /* memcpy */
#include <cassert>      /* assert */


#define TEST_RANDOM_SEED 1234567

void quick_sort(int *arr, size_t left, size_t right);
void swap(int &val_1, int &val_2);
void testcase_0(void);
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

size_t partition(int *arr, size_t left, size_t right)
{
    int pivot_val = arr[left];

    size_t low_index = left;

    for (size_t i = low_index+1; i < right; ++i)
    {
        if (arr[i] < pivot_val)
        {
            ++low_index;
            swap(&arr[i], &arr[low_index]);           
        }
    }

    if (low_index != left)
        swap(&arr[left], &arr[low_index]);

    return low_index;

}
void quick_sort(int *arr, size_t left, size_t right)
{
    if (left >= right) return;

    size_t pivot_pos = partition(arr, left, right);

    quick_sort(arr, left, pivot_pos);
    quick_sort(arr, pivot_pos+1, right);
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

    quick_sort(arr, 0, 1000);

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

    quick_sort(arr, 0, 10000);

    for (size_t i = 1; i < 10000; ++i)
    {
        assert(arr[i] >= arr[i-1]);
    }
}



