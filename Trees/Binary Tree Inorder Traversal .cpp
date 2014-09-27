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
    vector<int> inorderTraversal(TreeNode *root) {
        if(root == NULL) return res;
        if(root->left != NULL) inorderTraversal(root->left);
        res.push_back(root->val);
        if(root->right != NULL) inorderTraversal(root->right);
        return res;
    }
};
