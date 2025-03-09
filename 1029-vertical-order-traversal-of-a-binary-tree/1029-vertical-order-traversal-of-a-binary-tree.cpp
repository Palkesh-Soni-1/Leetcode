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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>m;
        queue<pair<TreeNode* , pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto z = q.front();
            q.pop();
            TreeNode* l = z.first;
            int x = z.second.first;
            int y = z.second.second;
            m[x][y].insert(l->val);
            // cout<<m[x][y]<<endl;
            if(l->left)
            q.push({l->left,{x-1,y+1}});
            if(l->right)
            q.push({l->right,{x+1,y+1}});
        }
        vector<vector<int>>ans;
        for(auto x : m)
        {
            // cout<<x[x][y]
            vector<int>ver;
            for(auto y : x.second)
            {
                ver.insert(ver.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(ver);
        }
        return ans;
    }
};