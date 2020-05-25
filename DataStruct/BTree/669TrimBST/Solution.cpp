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

//First attempt: pre order traverse
//TEST: 20 ms all tests faster than 86.58%

class Solution {
public:
    void trim(TreeNode* &root, int L, int R){
        if(root == NULL) return;
        
        while(root->val > R || root->val < L){
            if(root->val > R)root = root->left;
            if(root == NULL)return;
            if(root->val < L)root = root->right;
            if(root == NULL)return;
        }
        
        if(root == NULL) return;
        
        if(root->left != NULL){
            if(root->left->val < L){
                root->left = root->left->right;                
            }
            
            trim(root->left, L, R);
        }
        
        if(root->right != NULL){
            if(root->right->val > R){
                root->right = root->right->left;
            }
            
            trim(root->right, L, R);            
        }
    }
    
    TreeNode* trimBST(TreeNode* root, int L, int R) {                
        trim(root, L, R);
        
        return root;
    }
};