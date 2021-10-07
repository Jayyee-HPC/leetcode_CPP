/**
 * @file     queue.cpp
 */
/* Author J.Y. */

/** Queue
 * Queue is a linear data structure which follows a particular order in which the operations are performed.
 * The order is FIFO (First In First Out).
 **/

//g++ -std=c++11 -o prog queue.cpp

#include <stdio.h>
#include <cstddef>
#include <iostream>
#include <chrono>       /* std::chrono::seconds, std::chrono::milliseconds */
#include <stdlib.h>     /* srand, rand */
#include <cstring>      /* memcpy */
#include <cassert>      /* assert */
#include <queue>

#define TEST_RANDOM_SEED 1234567

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

void testcase_1(void)
{
    std::queue<int> queue;

    srand(TEST_RANDOM_SEED);
    for (size_t i = 0; i < 1000; ++i)
    {
        queue.push(rand() % 10000 + 1);
    }
    
    while (!queue.empty())
        queue.pop();
}

void testcase_2(void)
{
    std::queue<int> queue;

    srand(TEST_RANDOM_SEED);
    for (size_t i = 0; i < 10000; ++i)
    {
        queue.push(rand() % 100000 + 1);
    }
    
    while (!queue.empty())
        queue.pop();
}


