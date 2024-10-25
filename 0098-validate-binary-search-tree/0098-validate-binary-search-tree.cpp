// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//  * right(right) {}
//  * };
//  */
// class Solution {
// public:
//     bool ans(TreeNode* root) {
//         if (root->left) {
//             if (root->left->val >= root->val) {
//                 return false;
//             }
//         }
//         if (root->right) {

//             if (root->right->val <= root->val) {
//                 return false;
//             }
//         }
//         if (root->left)
//             ans(root->left);
//         if (root->right)
//             ans(root->right);
//         return true;
//     }
//     bool isValidBST(TreeNode* root) {
//         if (root == NULL)
//             return true;
//         return ans(root);
//     }
// };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);        
    }

private:
    bool valid(TreeNode* node, long minimum, long maximum) {
        if (!node) return true;

        if (!(node->val > minimum && node->val < maximum)) return false;

        return valid(node->left, minimum, node->val) && valid(node->right, node->val, maximum);
    }    
};