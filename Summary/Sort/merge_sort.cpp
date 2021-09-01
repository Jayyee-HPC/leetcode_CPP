/**
 * @file     merge_sort.cpp
 */
/* Author J.Y. */

/** Merge sort
 * MergeSort is a Divide and Conquer algorithm.
 * It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.
 *  The merge() function is used for merging two halves.
 */

//g++ -std=c++11 -o prog merge_sort.cpp

#include <stdio.h>
#include <cstddef>
#include <iostream>
#include <chrono>       /* std::chrono::seconds, std::chrono::milliseconds */
#include <stdlib.h>     /* srand, rand */
#include <cstring>      /* memcpy */
#include <cassert>      /* assert */


#define TEST_RANDOM_SEED 1234567

void merge_sort(int *arr, size_t left, size_t right);
void merge(int *arr, size_t left, size_t mid, size_t right);

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

void merge_sort(int *arr, size_t left, size_t right)
{
    if (left+1 >= right) return;

    size_t mid = left + (right - left)/2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid, right);

    merge(arr, left, mid, right);
}

void merge(int *arr, size_t left, size_t mid, size_t right)
{
    int *left_arr = (int *)malloc(sizeof(int)* (mid - left));
    for (size_t i = 0; i < mid-left; ++i)
        left_arr[i] = arr[left+i];

    int *right_arr = (int *)malloc(sizeof(int)* (right - mid));
    for (size_t i = 0; i < right-mid; ++i)
        right_arr[i] = arr[mid+i];

    size_t replace_pos = left;

    size_t left_counter = 0;
    size_t right_counter = 0;

    while (left_counter < mid-left && right_counter < right - mid)
    {
        if (left_arr[left_counter] < right_arr[right_counter])
        {
            arr[replace_pos] = left_arr[left_counter];
            ++replace_pos;
            ++left_counter;
        }
        else
        {
            arr[replace_pos] = right_arr[right_counter];
            ++replace_pos;
            ++right_counter;
        }
    }

    while (left_counter < mid-left)
    {
        arr[replace_pos] = left_arr[left_counter];
        ++replace_pos;
        ++left_counter;
    }

    while (right_counter < right - mid)
    {
        arr[replace_pos] = right_arr[right_counter];
        ++replace_pos;
        ++right_counter;
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

    merge_sort(arr, 0, 1000);

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

    merge_sort(arr, 0, 10000);

    for (size_t i = 1; i < 10000; ++i)
    {
        assert(arr[i] >= arr[i-1]);
    }
}



