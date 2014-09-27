/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> res;
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if(root == NULL) return res;
        res.push_back(root->val);
        if(root->left != NULL) preorderTraversal(root->left);
        if(root->right != NULL) preorderTraversal(root->right);
        return res;
    }
};
