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

//Fancy solution: two pointer approach
//TEST: 40ms all tests faster than 90.13% (Same speed)

class Solution {
public:
    vector<int>v;
    void inOrderTraverse(TreeNode* root)
    {
        if(root==NULL)return;
        inOrderTraverse(root->left);
        v.push_back(root->val);
        inOrderTraverse(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        inOrderTraverse(root);
        
        int i=0,j=v.size()-1;
        while(i<j)
        {
            if(v[i]+v[j]==k) return true;          //two pointer approach to find if answer exists.
            else if(v[i]+v[j]<k) i++;
            else j--;
        }
        return false;
    }
};