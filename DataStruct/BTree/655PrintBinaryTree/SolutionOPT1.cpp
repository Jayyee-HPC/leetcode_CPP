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
//Secont attempt: using queues 
//TEST: 4ms all tests faster than 67.63%
class Solution {
    
private:
    vector<vector<string>> queueToVector(vector<queue<string>> *qResult) {
        vector<vector<string>> result;
        for(vector<queue<string>>::iterator itr = qResult->begin(); 
                    itr < qResult->end(); ++itr){
            vector<string> tmpStrVect;
            while(!((*itr).empty())){
                tmpStrVect.push_back((*itr).front());
                (*itr).pop();
            }
            result.push_back(tmpStrVect);
        }
        return result;   
    }
    
public:
    vector<vector<string>> printTree(TreeNode* root) {
        vector<queue<string>> qResult;
        
        queue<TreeNode*> tmpQueue;
        TreeNode* tmpNode;
     
        queue<string> initStrQueue;
        if(root == NULL){
            initStrQueue.push("");  
            qResult.push_back(initStrQueue);
            return queueToVector(&qResult);
        }else{
            initStrQueue.push(to_string(root->val)); 
            qResult.push_back(initStrQueue);
        }
        
        tmpQueue.push(root);
        while(1){
            //break flag
            bool isAllNodeNull = true;
            
            queue<TreeNode*> tmpQueueBuffer;
            queue<string> tmpStringQueue;
            
            while(!(tmpQueue.empty())){
                tmpQueueBuffer.push(tmpQueue.front());
                tmpQueue.pop();
            }
            
            while(!(tmpQueueBuffer.empty())){
                tmpNode = tmpQueueBuffer.front();
                tmpQueueBuffer.pop();
                if(tmpNode == NULL){
                    tmpQueue.push(NULL);
                    tmpQueue.push(NULL);
                    tmpStringQueue.push("");
                    tmpStringQueue.push("");
                    tmpStringQueue.push("");
                }else{
                    
                    tmpQueue.push(tmpNode->left);
                    tmpQueue.push(tmpNode->right);
                    if(tmpNode->left != NULL){
                        isAllNodeNull = false;
                       tmpStringQueue.push(to_string(tmpNode->left->val));  
                    }else{
                       tmpStringQueue.push(""); 
                    }
                    
                    tmpStringQueue.push(""); 
                    
                    if(tmpNode->right != NULL){
                        isAllNodeNull = false;
                        tmpStringQueue.push(to_string(tmpNode->right->val));
                    }else{
                        tmpStringQueue.push(""); 
                    }
                } 
                if((!(tmpQueueBuffer.empty())))tmpStringQueue.push("");
            }
                        
            //break point
            if(isAllNodeNull)break;
            
            //Update previous string vectors
            for(vector<queue<string>>::iterator itr = qResult.begin(); itr < qResult.end(); ++itr){
                queue<string> tmpQueueStrUpdate;
                while(!((*itr).empty())){
                    tmpQueueStrUpdate.push("");
                    tmpQueueStrUpdate.push((*itr).front());
                    tmpQueueStrUpdate.push("");
                    (*itr).pop();
                    if(!((*itr).empty())){
                        tmpQueueStrUpdate.push((*itr).front());
                        (*itr).pop();
                    }
                }
                
                while(!tmpQueueStrUpdate.empty()){
                    (*itr).push(tmpQueueStrUpdate.front());
                    tmpQueueStrUpdate.pop();
                }
            }
            
            qResult.push_back(tmpStringQueue);
        }
        
        //Fix string vectors' sizes to odd
        //for(vector<vector<string>>::iterator itr = result.begin(); itr < result.end(); ++itr){
          //      if(!((*itr).size() % 2)){
            //        (*itr).insert ( (*itr).begin() + (*itr).size() / 2 , "");
              //  }
        //}
        
        return queueToVector(&qResult);
    }

};