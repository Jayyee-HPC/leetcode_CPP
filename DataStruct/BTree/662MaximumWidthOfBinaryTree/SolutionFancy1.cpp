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

//Fancy solution: 
//In general, when binary tree is represented in array we traverse to left and right using 2n and 2n+1 where n is the position of current element.
//e use same idea, for every node we encounter we store its position in that level and also maintain prev and curr variables, containing left most node's rank/position and right most node's rank/position.
//Finally when we are done processing all nodes at a given level and we got our left and right most nodes positions set to prev and curr then we find the width as (curr-prev+1) after each level. Since we have many levels, we have to keep maintaining the max answer after each level.
//TEST: 8ms all tests faster than 64.58%
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode*,double>> que; // using double because of a test case where it crosses limit of long long for levels more than 32
        double ans = 0;
        if(root==NULL)
            return ans;
        
        que.push({root,1}); 
        while(!que.empty())
        {// level-order traversal
            int n = (int)que.size();
            double prev = 0;
            double curr = 0;
            while(n--)
            {
                pair<TreeNode*,double> temp = que.front();
                curr = temp.second;
                que.pop();
                if(temp.first->left!=NULL)
                    que.push({temp.first->left,2*temp.second-1});
                if(temp.first->right!=NULL)
                    que.push({temp.first->right,2*temp.second});
                if(prev==0) // For the first node in the queue, there is no prev so prev will be curr.
                    prev = curr;
            }
            ans = max(ans,curr-prev+1);
        }
        return ans;
    }
};