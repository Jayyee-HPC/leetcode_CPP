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

//Post order traversal
//TEST: 16 ms, faster than 96.31% 

class Solution {
public:
    int tilt = 0;
    
    int postorder(TreeNode* root){
        if (root == NULL) return 0;
        int leftSum = postorder(root->left);
        int rightSum = postorder(root->right);
        tilt += abs(leftSum - rightSum);
        return leftSum + rightSum + root->val;
    }
    
    int findTilt(TreeNode* root) {
        postorder(root);
        
        return tilt;
    }
};