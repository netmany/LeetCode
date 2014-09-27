/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
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
    TreeNode *first = NULL, *second = NULL, *pre = NULL;
    void dfs(TreeNode *root){
        if(root == NULL) return;
        if(root->left) dfs(root->left);
        if(pre != NULL && pre->val > root->val){
            if(first == NULL) first = pre; 
            second = root;
        }
        pre = root;
        if(root->right) dfs(root->right);
    }
public:
    void recoverTree(TreeNode *root) {
        dfs(root);
        int t = first->val; first->val = second->val; second->val = t;
    }
};
