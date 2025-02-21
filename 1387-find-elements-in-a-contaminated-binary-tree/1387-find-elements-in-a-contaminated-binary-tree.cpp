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
class FindElements{
    private:
    unordered_set<int>store;
    void dfs(TreeNode* root, int value)
    {
        if(root==NULL)
        return;

        store.insert(value);
        int left = 2*(value)+1;
        int right = 2*(value)+2;

        dfs(root->left, left);
        dfs(root->right, right);
    }


    public:
    FindElements(TreeNode* root)
    {
        dfs(root, 0);
    }

    bool find(int target)
    {
        return store.count(target)>0;
    }
};




// class FindElements {
//     TreeNode* root;
// public:
//     FindElements(TreeNode* root) {
//         root->val=0;
//         if(root->left)
//         {
//             fillleft(root->left,0);
//         }
//         if(root->right)
//         {
//             fillright(root->right,0);
//         }
//     }
//     bool bfs(int target, TreeNode* root)
//     {
//         cout<<root->val<<endl;
//         // if(root->val==target)
//         // return true;

//         // if(root->left)
//         // bfs(target, root->left);

//         // if(root->right)
//         // bfs(target, root->right);

//         return false;
//     }
//     bool find(int target) {
//         // return true;
//         return bfs(target, root);
//     }

//     void fillleft(TreeNode* root, int x)
//     {
//         if(!root)
//         return;
//         root->val = 2*x+1;
//         x = root->val;
//         if(root->left)
//         {
//             fillleft(root->left, x);
//         }
//         if(root->right)
//         {
//             fillright(root->right,x);
//         }
//     }

//     void fillright(TreeNode* root, int x)
//     {
//         if(!root)
//         return;
//         root->val = 2*x+2;
//         x = root->val;
//         if(root->left)
//         {
//             fillleft(root->left,x);
//         }
//         if(root->right)
//         {
//             fillright(root->right,x);
//         }
//     }
// };

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */