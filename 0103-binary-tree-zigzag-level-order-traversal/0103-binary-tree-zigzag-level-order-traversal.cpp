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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL)
        return v;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=true;
        while(!q.empty())
        {
            int n = q.size();
            vector<int>z(n);
            for(int i=0;i<n;i++)
            {
                TreeNode* store = q.front();
                q.pop();
                int ind;
                if(flag)
                ind = i;
                else
                ind = n-1-i;
                z[ind]=store->val;
                if(store->left)
                q.push(store->left);
                if(store->right)
                q.push(store->right);
            }
            flag = !flag;
            v.push_back(z);
        }
        return v;
    }
};