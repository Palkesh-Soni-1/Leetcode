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
    map<pair<int,int>, vector<TreeNode*>>mp;
    vector<TreeNode*> solve(int start, int end)
    {
        vector<TreeNode*>ans;
        if(start>end)
        {
            ans.push_back(NULL);
            return mp[{start,end}]=ans;
        }
        if(mp.find({start,end})!=mp.end())
        return mp[{start,end}];
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> left = solve(start,i-1);
            vector<TreeNode*> right = solve(i+1,end);

            for(auto j: left)
            {
                for(auto k:right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = j;
                    root->right = k;
                    ans.push_back(root);
                }
            }
        }
        return mp[{start,end}]=ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res = solve(1,n);
        return res;
    }
};