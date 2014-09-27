/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
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
    bool subSym(TreeNode *left, TreeNode *right){
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;
        return left->val == right->val &&
            subSym(left->left, right->right) &&
            subSym(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) return true;
        return subSym(root->left, root->right);
    }
};
