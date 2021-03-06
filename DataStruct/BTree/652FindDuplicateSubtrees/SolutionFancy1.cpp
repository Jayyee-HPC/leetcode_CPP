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

//Fancy solution: dfs search, map
//TEST: 80ms all tests faster than 23.71% (Not by me)

class Solution {
public:
    map<string, int> rootMap;
    vector<TreeNode*> out;
    string dfs(TreeNode* node)
    {
        if(node == NULL) return "";
        string s = to_string(node->val)+" ";
        if(node->left == NULL && node->right == NULL) 
        {
            rootMap[s]++;
            if(rootMap[s] == 2) out.push_back(node);
            return s;
        }
        string l = dfs(node->left);
        string r = dfs(node->right);
        if(node->left == NULL) s += "N ";
        else s += l;
        if(node->right == NULL) s += "N ";
        else s += r;
        rootMap[s]++;
        if(rootMap[s] == 2) out.push_back(node);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return out;
    }
};