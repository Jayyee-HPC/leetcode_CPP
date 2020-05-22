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
//TEST: 64ms all tests faster than 97.8%

class Solution {
private:
    TreeNode* updateMBT(TreeNode* root, int item){
        if(NULL == root){
            root = new TreeNode(item);
            return root;
        }else if(item < root->val){
            root->right = updateMBT(root->right, item);
            return root;
        }else if(item > root->val){
            TreeNode* newRoot = new TreeNode(item);
            newRoot->left = root;
            return newRoot;
        }        
        return NULL;
    }
    
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = NULL;
        for(vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr){
            if(NULL == root){
                root = new TreeNode(*itr);
            }else{
                root = updateMBT(root, *itr);
            }
        }
        
        return root;
    }
};