/**
 * @file     hash_table.cpp
 */
/* Author J.Y. */

/** Hash table
 * A Hash Table in C/C++ (Associative array) is a data structure that maps keys to values. 
 * This uses a hash function to compute indexes for a key.
 * C++ std::unordered_map()
 **/

/*
The idea of hashing is to distribute the entries (key/value pairs) across an array of buckets. Given a key, the algorithm computes an index that suggests where the entry can be found:

index = f(key, array_size)
Often this is done in two steps:
hash = hashfunc(key)
index = hash % array_size

*/

/*
unordered_map: no ordering, Hash Table, search/insertion/deletion O(1) -> Average O(n) -> Worst Case
map: increasing  order, Self balancing BST (red-black tree), search log(n), insertion/deletion log(n) + Rebalance
*/

//g++ -std=c++11 -o prog hash_table.cpp

#include <stdio.h>
#include <cstddef>
#include <iostream>
#include <chrono>       /* std::chrono::seconds, std::chrono::milliseconds */
#include <stdlib.h>     /* srand, rand */
#include <cstring>      /* memcpy */
#include <cassert>      /* assert */
#include <unordered_map>
#include <map>

#define TEST_RANDOM_SEED 1234567

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

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
    std::unordered_map<int, int> umap;
    std::map<int, int> map;
    TreeNode * root = new TreeNode(500);
    srand(TEST_RANDOM_SEED);
    
    for (size_t i = 0; i < 100; ++i)
    {
        TreeNode *temp_node = new TreeNode(rand() % 1000 + 1);

        TreeNode *curr = root, *prev;

        while (curr != nullptr)
        {
            prev = curr;
            if (temp_node->val <= curr->val)
                curr = curr->left;
            else
                curr = curr->right;
        }

        if (temp_node->val <= prev->val)
            prev->left = temp_node;
        else
            prev->right = temp_node;
    }

    std::cout<<"Test 1 unordered_map"<<std::endl;
    for (auto &itr : umap)
        std::cout<<itr.first<<" : "<<itr.second<<std::endl;

    std::cout<<"Test 1 map"<<std::endl;
    for (auto &itr : map)
        std::cout<<itr.first<<" : "<<itr.second<<std::endl;
}

void testcase_2(void)
{
    std::unordered_map<int, int> umap;
    std::map<int, int> map;

    srand(TEST_RANDOM_SEED);
    for (size_t i = 0; i < 20; ++i)
    {
        int temp_val = rand() % 200 + 1;
        umap[temp_val] = i;
        map[temp_val] = i;
    }

    std::cout<<"Test 2 unordered_map"<<std::endl;
    for (auto &itr : umap)
        std::cout<<itr.first<<" : "<<itr.second<<std::endl;

    std::cout<<"Test 2 map"<<std::endl;
    for (auto &itr : map)
        std::cout<<itr.first<<" : "<<itr.second<<std::endl;
}

