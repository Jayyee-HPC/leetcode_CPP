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
//TEST: Time Limit Exceeded 123 / 169 test cases passed.

class Solution {
public:
    
    vector<TreeNode*> result;
    
    bool isTwoTreesEqual(TreeNode* tree1, TreeNode* tree2){
        if(tree1 == NULL && tree2 == NULL)  return true;
        
        if((tree1 == NULL && tree2 != NULL) ||
           (tree1 != NULL && tree2 == NULL)) return false;
           
        if(tree1->val == tree2->val && tree1 != tree2){
            return(isTwoTreesEqual(tree1->left, tree2->left) &&
                  isTwoTreesEqual(tree1->right, tree2->right));
        }else{
            return false;
        }
    }

    int treeHeight(TreeNode* root){
        if(root == NULL)return 0;
        
        return (1 + treeHeight(root->left)) > (1 + treeHeight(root->right))
                ? (1 + treeHeight(root->left)) : (1 + treeHeight(root->right));
    }

    
    void findDup(TreeNode* root, TreeNode* node){   
        if(root == NULL || node == NULL)return;
        
        if(root == node) return;
        
        if(isTwoTreesEqual(root, node)){
            for(int i = 0; i < result.size(); ++i){
                if(isTwoTreesEqual(result[i], node))return;
                if(result[i] == node)return;
            }
            result.push_back(node);
        }else{
            if(root->left != node)
            findDup(root->left, node);
            if(root->right != node)
            findDup(root->right, node);
        }
        
    }
    

    void preOrderTraverse(TreeNode* root, TreeNode* node){        
        findDup(root, node);
        
        if(node != NULL){
            preOrderTraverse(root, node->left);
            preOrderTraverse(root, node->right);
        }
    }
           
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root == NULL) return result;
        
        preOrderTraverse(root, root);
        
        return result;
    }
};