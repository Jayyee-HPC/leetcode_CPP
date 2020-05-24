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

//First attempt: construct a maximum tree
//TEST: 40ms all tests faster than 90.13%

class Solution {
private:
    bool find(TreeNode* root, int k, TreeNode* node){
        if(root == NULL || node == NULL)
            return false;
        
        if(root->val == k && root != node)
            return true;
        
        if(root->val < k)
            return find(root->right, k, node);
        
        if(root->val > k) 
            return find(root->left, k,  node);
        
        return false;
    }
    
    bool preOrderTraverse(TreeNode* root, TreeNode* node, int k) {
        if(node == NULL || root == NULL) return false;
        
        return (find(root, k - node->val, node) 
                || preOrderTraverse(root, node->left, k)
                || preOrderTraverse(root, node->right, k));
    }

public:
    bool findTarget(TreeNode* root, int k) {
        return preOrderTraverse(root, root, k);
    }
};