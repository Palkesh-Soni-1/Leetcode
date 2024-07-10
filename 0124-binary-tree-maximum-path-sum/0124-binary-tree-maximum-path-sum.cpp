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
public:
    
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        ans(root,maxi);
        return maxi;
    }
    int ans(TreeNode* root, int&maxi)
    {
        if(root==NULL)
        return 0;

        int left = ans(root->left, maxi);
        int right = ans(root->right, maxi);
        
        maxi = max(maxi, root->val+left+right);
        if(root->val + max(right,left)<0)
        return 0;
        return root->val + max(left,right);
    }
};