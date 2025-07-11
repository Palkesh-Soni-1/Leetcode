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

    void dfs(TreeNode* root, vector<int>&v)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            v.push_back(root->val);
            return;
        }
        if(root->left)
        dfs(root->left, v);
        if(root->right)
        dfs(root->right,v);
        return;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leaf1,leaf2;
        dfs(root1, leaf1);
        dfs(root2,leaf2);
        return leaf1==leaf2;
    }
};