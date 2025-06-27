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

    void solve(TreeNode* root, long long int targetSum, long long int&ans)
    {
        if(root==NULL)
        return;

        if(root->val==targetSum)
        {
            ans++;
        }
        // solve(root->left, targetSum, ans);
        solve(root->left, targetSum-(root->val), ans);

        // solve(root->right, targetSum, ans);
        solve(root->right, targetSum-(root->val), ans);
    }
public:
    long long int ans=0;
    int pathSum(TreeNode* root, long long int targetSum) {
        if(root){
            solve(root,targetSum,ans);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return ans;
    }
};