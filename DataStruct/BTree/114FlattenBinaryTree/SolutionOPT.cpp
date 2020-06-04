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

//pre-order traversal, using queue instead of vector
//TEST: 8 ms, faster than 67.82% 

class Solution {
public:
    queue<int> qOfVals;
    
    void preOrderTraversal(TreeNode* &root){
        if (root == NULL) return;
        
        qOfVals.push(root->val);
        
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        preOrderTraversal(root);
        root->left = root->right = NULL;
        
        qOfVals.pop();
        TreeNode* tmpNode = root;
        while(! qOfVals.empty()){            
            tmpNode->right = new TreeNode(qOfVals.front()); 
            tmpNode = tmpNode->right;
            qOfVals.pop();
        }
        
    }
};