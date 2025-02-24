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
class Solution {

    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* previous = new TreeNode(INT_MIN);

    void solve(TreeNode*root)
    {
        if(!root)
        return;

        solve(root->left);

        if(first==NULL&&previous->val>root->val)
        {
            first = previous;
        }

        if(first!=NULL&&previous->val>root->val)
        {
            second = root;
        }
        previous=root;

        solve(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        solve(root);
        swap(first->val, second->val);
    }
};