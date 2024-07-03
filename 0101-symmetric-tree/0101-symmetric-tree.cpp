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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        return true;
        if(root->left==NULL&&root->right==NULL)
        return true;
        if(root->left==NULL&&root->right!=NULL)
        return false;
        if(root->left!=NULL&&root->right==NULL)
        return false;
        //left root left right
        vector<int>v1;
        queue<TreeNode*>q;
        q.push(root->left);
        v1.push_back(root->left->val);
        while(!q.empty())
        {
            TreeNode* p = q.front();
            q.pop();
            if(p->left)
            {
               q.push(p->left);
               v1.push_back(p->left->val); 
            }
            if(!p->left)
            v1.push_back(-1);
            if(p->right)
            {
               q.push(p->right); 
               v1.push_back(p->right->val); 
            } 
            if(!p->right)
            v1.push_back(-1);
        }
        //left root right left
        vector<int>v2;
        queue<TreeNode*>q2;
        q2.push(root->right);
        TreeNode*x = root->right;
        v2.push_back(x->val); 
        while(!q2.empty())
        {
            TreeNode* p = q2.front();
            q2.pop();
            if(p->right)
            {
               q2.push(p->right);
               v2.push_back(p->right->val); 
            }
            if(!p->right)
            v2.push_back(-1);
            if(p->left)
            {
                q2.push(p->left);
                v2.push_back(p->left->val); 
            }
            if(!p->left)
            v2.push_back(-1);
        }
        if(v1.size()!=v2.size())
        return false;
        int n = v1.size();
        for(int i=0;i<n;i++)
        {
            cout<<v1[i]<<" "<<v2[i]<<endl;
            if(v1[i]!=v2[i])
            return false;
        }
        return true;
    }
};