/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    TreeNode * helper(TreeNode *root) {
        if(root == NULL) return NULL;
        if(root->left == NULL && root->right == NULL) return root;
        TreeNode *left, *right;
        left = helper(root->left);
        right = helper(root->right);
        root->left = NULL;
        if(left == NULL) {
            root->right = right;
        }else{
            root->right = left; left = root;
            while(left->right != NULL) left = left->right;
            left->right = right;
        }
        return root;
    }
public:
    void flatten(TreeNode *root) {
        helper(root);
    }
};
