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

//First attempt: bfs
//TEST: 48ms all tests faster than 7.38%

class Solution {
public:

    int widthOfBinaryTree(TreeNode* root) {
        if(NULL == root)return 1;
        
        int maxWidth = 1;
        queue<TreeNode*>* qTreeNode = new queue<TreeNode*>;        
        qTreeNode->push(root);
        
        while(1){
                        
            //if(qTreeNode->size() > maxWidth)maxWidth = qTreeNode->size();
            
            bool allNullNodes = true;
            bool findFirstValid = false;
            queue<TreeNode*>* tmpQ = new queue<TreeNode*>;
            int tmpNullQ = 0;
            //int start = 0;
            //int end = 0;
            //int tmpEnd = 0;        
        
            while(!qTreeNode->empty()){
                TreeNode* tmpNode = qTreeNode->front();
                qTreeNode->pop();
                
                if(tmpNode != NULL){                                                                              
                    if(tmpNode->left != NULL && !findFirstValid){
                        tmpQ->push(tmpNode->left);
                        //tmpEnd = end = start+1;
                        findFirstValid = true;
                    }else if(tmpNode->left != NULL && findFirstValid){
                        for(int i = 0; i < tmpNullQ; ++i)tmpQ->push(NULL);
                        tmpQ->push(tmpNode->left);
                        //++tmpEnd;
                        //end = tmpEnd;
                        tmpNullQ = 0;
                    }else if(tmpNode->left == NULL && !findFirstValid){
                        //++start;
                    }else if(tmpNode->left == NULL && findFirstValid){
                        //tmpQ->push(tmpNode->left);
                        ++tmpNullQ;
                        //++tmpEnd;
                    }

                    if(tmpNode->right != NULL && !findFirstValid){
                        tmpQ->push(tmpNode->right);
                        //tmpEnd = end = start+1;
                        findFirstValid = true;
                    }else if(tmpNode->right != NULL && findFirstValid){
                        for(int i = 0; i < tmpNullQ; ++i)tmpQ->push(NULL);
                        
                        tmpQ->push(tmpNode->right);
                        //++tmpEnd;
                        //end = tmpEnd;
                        
                        tmpNullQ = 0;
                    }else if(tmpNode->right == NULL && !findFirstValid){
                        //++start;
                    }else if(tmpNode->right == NULL && findFirstValid){
                        //++tmpEnd;
                        ++tmpNullQ;
                    }
                    
                    
                    if(tmpNode->left != NULL || tmpNode->right != NULL)
                        allNullNodes = false;
                }else{
                    if(findFirstValid){
                        tmpNullQ += 2;
                    }
                }
            }
           
            
            if(allNullNodes)break;
            
 if(tmpQ->size() > maxWidth)maxWidth = tmpQ->size();
            
            qTreeNode = tmpQ;
        }
        
        return maxWidth;
        
    }
};