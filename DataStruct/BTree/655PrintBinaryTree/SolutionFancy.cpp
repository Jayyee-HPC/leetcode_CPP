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
//Not by me: get depth of the tree then fullfil all empty space
//TEST: 0ms all tests faster than 100%
class Solution {
public:
    int getDepth(TreeNode *root){
        if(!root) return 0;
        return max(getDepth(root->left), getDepth(root->right))+1;
    }
    
    void printUtil(TreeNode *root, vector<vector<string>> &ans, 
                                int start, int end, int depth){
        if(!root) return;
        int mid = start + (end-start)/2;
        ans[depth][mid] = to_string(root->val);
        printUtil(root->left, ans, start, mid-1, depth+1);
        printUtil(root->right, ans, mid+1, end, depth+1);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int d = getDepth(root);
        vector<vector<string>> ans(d, vector<string>(pow(2, d)-1, "")); // width  = 2^d - 1
        printUtil(root, ans, 0, pow(2, d)-1, 0);
        return ans;
    }
};