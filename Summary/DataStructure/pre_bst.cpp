/**
 * @file     pre_bst.cpp
 */
/* Author J.Y. */

/** Construct BST from pre-order traversal results 
 * 
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*****************************************************************************
Solution 1:
In a preorder traversal, we visit the root first.
So in each iteration, the first element - preorder[i] - is the root
then we find the left and right subtrees and construct the tree recursively.
In the left subtree, the maximum value is the current root.
In the right subtree, the maximum value is the previous root.

******************************************************************************/
int pos = 0;

TreeNode* bst_reconstruct(vector<int> &preorder, int max_val = INT_MAX)
{
    if (pos >= preorder.size() || preorder[pos] > max_val)
        return nullptr;

    TreeNode *root = new TreeNode(preorder[pos]);

    root->left = bst_reconstruct(preorder, root->val);
    root->right = bst_reconstruct(preorder, max_val);

    return root;
}

/*****************************************************************************
Solution 2:
Make a function which will insert your elements from the preorder array 
into the binary search tree in the predefined form of the binary search tree.
******************************************************************************/

TreeNode* bstFromPreorder(vector<int>& preorder)
{
    TreeNode* root=new TreeNode();
    
    root->val=preorder[0];
    
    for (int i = 1; i < preorder.size(); i++)
    {
        my_push_back(root, preorder[i]);
    }
    
    return root;
}

void my_push_back(TreeNode* root, int val_to_insert)
{
    if (val_to_insert > root->val)
    {
        if (root->right == nullptr)
        {
            root->right=new TreeNode(val_to_insert);
        }
        else
        {
            my_push_back(root->right, val_to_insert);
        }
    }
    else if(val_to_insert < root->val)
    {
        if(root->left == nullptr)
        {
            root->left = new TreeNode(val_to_insert);
        }
        else
        {
            my_push_back(root->left, val_to_insert);
        }
    }
}
