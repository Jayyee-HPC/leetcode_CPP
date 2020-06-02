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

//First attempt: this problem is not clear enough. Treat a tree as a scale, and accumulate tilt from bottom up.
//NOT root->left - root->right
//NOT all left children - all right children
//TEST: 20 ms, faster than 85.31% 

class Solution {
public:
    int sumOfTree(TreeNode* root, int& value){
        if (NULL == root)return 0;
        
        int left = 0;
        int right = 0;
        if (root->left != NULL){
            left = sumOfTree(root->left, value);            
        }
        
        if (root->right != NULL){
            right = sumOfTree(root->right, value);           
        }
        
        value += abs(left - right);
        
        return left + right + root->val;
    }
    
    int findTilt(TreeNode* root) {
        int result = 0;
        
        if (NULL == root)return result;
        
        sumOfTree(root, result);
        
        return result;
    }
};