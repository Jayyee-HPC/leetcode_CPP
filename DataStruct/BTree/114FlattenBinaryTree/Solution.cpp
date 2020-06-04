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

//First attempt: pre-order traversal
//TEST: 8 ms, faster than 67.82% 

class Solution {
public:
    vector<int> vect;
    
    void preOrderTraversal(TreeNode* &root){
        if (root == NULL) return;
        
        vect.push_back(root->val);
        
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        preOrderTraversal(root);
        root->left = root->right = NULL;
        //root = newRoot;  
        for (int i = 1; i < vect.size(); ++i){
            TreeNode* tmpNode = root;
            while(tmpNode->right != NULL)tmpNode = tmpNode->right;
            
            tmpNode->right = new TreeNode(vect[i]); 
        }       
    }
};