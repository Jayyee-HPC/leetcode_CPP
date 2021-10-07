/**
 * @file     red_black_tree.cpp
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

//g++ -std=c++11 -o prog red_black_tree.cpp

#include <stdio.h>
#include <cstddef>
#include <iostream>
#include <chrono>       /* std::chrono::seconds, std::chrono::milliseconds */
#include <stdlib.h>     /* srand, rand */
#include <cstring>      /* memcpy */
#include <cassert>      /* assert */
#include <vector>
#include <bits/stdc++.h> /*INT_MAX, INT_MIN*/

#define TEST_RANDOM_SEED 1234567

enum Color {RED, BLACK};

struct TreeNode {
    int val;
    bool color;
    TreeNode *left, *right, *parent;
    TreeNode() : val(0), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(int x) : val(x), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), color(RED), left(left), right(right), parent(nullptr) {}
};


// Class to represent Red-Black Tree
class RBTree
{
private:
    TreeNode *root;
protected:
    void rotateLeft(TreeNode *&, TreeNode *&);
    void rotateRight(TreeNode *&, TreeNode *&);
    void fixViolation(TreeNode *&, TreeNode *&);
public:
    // Constructor
    RBTree() { root = NULL; }
    void insert(const int &n);
    void inorder();
    void levelOrder();
};

// A recursive function to do inorder traversal
void inorderHelper(TreeNode *root)
{
    if (root == NULL)
        return;
 
    inorderHelper(root->left);
    cout << root->val << "  ";
    inorderHelper(root->right);
}


/* A utility function to insert a new node with given key in BST */
TreeNode* BSTInsert(TreeNode* root, TreeNode *pt)
{
    /* If the tree is empty, return a new node */
    if (root == NULL)
       return pt;
 
    /* Otherwise, recur down the tree */
    if (pt->val < root->val)
    {
        root->left  = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }
 
    /* return the (unchanged) node pointer */
    return root;
}


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

void in_order_traversal(TreeNode *root, std::vector<int> &vect_nums)
{
    if (!root)
        return;

    in_order_traversal(root->left, vect_nums);
    vect_nums.push_back(root->val);
    in_order_traversal(root->right, vect_nums);
}

void pre_order_traversal(TreeNode *root, std::vector<int> &vect_nums)
{
    if (!root)
        return;

    vect_nums.push_back(root->val);
    pre_order_traversal(root->left, vect_nums);    
    pre_order_traversal(root->right, vect_nums);
}

void post_order_traversal(TreeNode *root, std::vector<int> &vect_nums)
{
    if (!root)
        return;

    post_order_traversal(root->left, vect_nums);   
    post_order_traversal(root->right, vect_nums);
    vect_nums.push_back(root->val);
}

// A recursive function to construct
// BST from pre[]. preIndex is used
// to keep track of index in pre[].
TreeNode* constructTreeUtil(std::vector<int> &pre, int* preIndex, int key,
                        int min, int max, int size)
{
    // Base case
    if (*preIndex >= size)
        return NULL;
 
    TreeNode* root = NULL;
 
    // If current element of pre[] is in range, then
    // only it is part of current subtree
    if (key >= min && key <= max) {
        // Allocate memory for root of this
        // subtree and increment *preIndex
        root = new TreeNode(key);
        *preIndex = *preIndex + 1;
 
        if (*preIndex < size) {
            // Construct the subtree under root
            // All nodes which are in range
            // {min .. key} will go in left
            // subtree, and first such node
            // will be root of left subtree.
            root->left = constructTreeUtil(pre, preIndex,
                                           pre[*preIndex],
                                           min, key, size);
        }
        if (*preIndex < size) {
            // All nodes which are in range
            // {key..max} will go in right
            // subtree, and first such node
            // will be root of right subtree.
            root->right = constructTreeUtil(pre, preIndex,
                                            pre[*preIndex],
                                            key, max, size);
        }
    }
 
    return root;
}
 
// The main function to construct BST
// from given preorder traversal.
// This function mainly uses constructTreeUtil()
TreeNode* constructTree(std::vector<int> &pre, int size)
{
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, pre[0],
                             INT_MIN, INT_MAX, size);
}

void testcase_1(void)
{
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

    std::vector<int> int_vect_nums;
    in_order_traversal(root, int_vect_nums);

    std::vector<int> pre_vect_nums;
    pre_order_traversal(root, pre_vect_nums);

    std::vector<int> post_vect_nums;
    post_order_traversal(root, post_vect_nums);

}

void testcase_2(void)
{
    TreeNode * root = new TreeNode(5);
    srand(TEST_RANDOM_SEED);

    for (size_t i = 0; i < 10; ++i)
    {
        TreeNode *temp_node = new TreeNode(rand() % 100 + 1);

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

    std::vector<int> in_vect_nums;
    in_order_traversal(root, in_vect_nums);

    std::vector<int> pre_vect_nums;
    pre_order_traversal(root, pre_vect_nums);

    TreeNode* newroot = constructTree(pre_vect_nums, pre_vect_nums.size());
    std::vector<int> in_vect_nums_2;
    in_order_traversal(newroot, in_vect_nums_2);

    std::cout<<newroot->val<<" "<<newroot->left<<" "<<newroot->right<<std::endl;  
    for (auto &itr : in_vect_nums)
        std::cout<<itr<<" ";

    std::cout<<std::endl;

    for (auto &itr : in_vect_nums_2)
        std::cout<<itr<<" ";

    std::cout<<std::endl;

}

