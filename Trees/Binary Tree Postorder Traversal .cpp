/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
*/

//---------------------------------------------------------------------------------
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
    void pT(vector<int> &res, TreeNode *root){
        if(root == NULL) return;
        pT(res, root->left);
        pT(res, root->right);
        res.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        pT(res, root);
        return res;
    }
};
