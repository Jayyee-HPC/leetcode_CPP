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

//Fancy solution: dfs search, unordered_map
//TEST: 44ms all tests faster than 85.67% (Not by me)

class Solution {
public:
    
    string dfs(TreeNode* root, unordered_map<string, int>& mm, vector<TreeNode*>& result){
        if(root == NULL) return "#";
        else{
            string id = dfs(root->left, mm, result) + dfs(root->right, mm, result) + to_string(root->val);
            if(mm.find(id) == mm.end()){
                mm[id] = 1;
            }
            else{
                if(mm[id] == 1) result.push_back(root);
                mm[id]++;
            }
            return id;
        }
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mm;
        vector<TreeNode*> result;
        dfs(root, mm, result);
        return result;
    }
};