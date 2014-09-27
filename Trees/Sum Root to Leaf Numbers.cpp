/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int sum(int prefix, TreeNode *root){
        if(root == NULL) return prefix;
        if(root->left == NULL) return sum(prefix * 10 + root->val, root->right);
        if(root->right == NULL) return sum(prefix * 10 + root->val, root->left);
        return sum(prefix * 10 + root->val, root->left) +
            sum(prefix * 10 + root->val, root->right);
    }
public:
    int sumNumbers(TreeNode *root) {
        return sum(0, root);
    }
};
