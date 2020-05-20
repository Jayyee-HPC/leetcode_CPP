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
//First attempt: using a list store each layer and then go downward
//TEST: 12ms all tests faster than 11%
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> result;
        
        list<TreeNode*> tmpVect;
        TreeNode* tmpNode;
        int counter = 1;
        
        vector<string> initStrVect;
        if(root == NULL){
            initStrVect.push_back("");  
            result.push_back(initStrVect);
            return result;
        }else{
            initStrVect.push_back(to_string(root->val)); 
            result.push_back(initStrVect);
        }
        
        tmpVect.push_back(root);
        while(1){
            //break point
            bool isAllNodeNull = true;
            for(list<TreeNode*>::iterator itr = tmpVect.begin(); itr != tmpVect.end(); ++itr){
                if((*itr) != NULL){
                    isAllNodeNull = false;
                    break;
                }
            }
            if(isAllNodeNull)break;
            
            list<TreeNode*> tmpVectBuffer;
            vector<string> tmpStringVect;
            
            while(!(tmpVect.empty())){
                tmpVectBuffer.push_back(tmpVect.back());
                tmpVect.pop_back();
            }
            
            while(!(tmpVectBuffer.empty())){
                tmpNode = tmpVectBuffer.back();
                tmpVectBuffer.pop_back();
                if(tmpNode == NULL){
                    tmpVect.push_back(NULL);
                    tmpVect.push_back(NULL);
                    tmpStringVect.push_back("");
                    tmpStringVect.push_back("");
                    tmpStringVect.push_back("");
                }else{
                    tmpVect.push_back(tmpNode->left);
                    tmpVect.push_back(tmpNode->right);
                    if(tmpNode->left != NULL){
                       tmpStringVect.push_back(to_string(tmpNode->left->val));  
                    }else{
                       tmpStringVect.push_back(""); 
                    }
                    
                    tmpStringVect.push_back(""); 
                    
                    if(tmpNode->right != NULL){
                        tmpStringVect.push_back(to_string(tmpNode->right->val));
                    }else{
                        tmpStringVect.push_back(""); 
                    }
                } 
                if((!(tmpVectBuffer.empty())))tmpStringVect.push_back("");
            }
                        
            //break point
            bool isAllStringSpace = true;
            for(vector<string>::iterator itr = tmpStringVect.begin(); itr != tmpStringVect.end(); ++itr){
                if((*itr) != ""){
                    isAllStringSpace = false;
                    break;
                }
            }
            if(isAllStringSpace)break;
            
            //Update previous string vectors
            for(vector<vector<string>>::iterator itr = result.begin(); itr < result.end(); ++itr){
                vector<string> tmpVectStrUpdate;
                for(vector<string>::iterator iitr = (*itr).begin(); iitr < (*itr).end(); ++iitr){
                    tmpVectStrUpdate.push_back("");
                    tmpVectStrUpdate.push_back(*iitr);
                    tmpVectStrUpdate.push_back("");
                    ++iitr;
                    if(iitr < (*itr).end())
                    tmpVectStrUpdate.push_back(*iitr);
                }
                (*itr).clear();
                for(vector<string>::iterator iitr = tmpVectStrUpdate.begin(); 
                    iitr < tmpVectStrUpdate.end(); ++iitr){
                    (*itr).push_back(*iitr);
                }
            }
            
            result.push_back(tmpStringVect);
        }
        
        return result;
    }
};