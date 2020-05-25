/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// bfs, using index
//TEST: 0-8ms faster than 100% - 64.58%.

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        widthOfBinaryTree(root, 0, 1);
        return width;
    }
    
    void widthOfBinaryTree(TreeNode *node, int level, unsigned index) {
        if (node == nullptr) return;
        if (minIndex.size() == level) minIndex.push_back(index);
        width = max(width, index - minIndex[level] + 1);
        widthOfBinaryTree(node->left, level + 1, index * 2);
        widthOfBinaryTree(node->right, level + 1, index * 2 + 1);
    }
private:
    vector<unsigned> minIndex;
    unsigned width = 0;
};