/*
Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode *build(vector<int> &inorder, int ibegin, int iend,
            vector<int> &postorder, int pbegin, int pend) {
        if(ibegin == iend) return NULL;
        TreeNode *root = new TreeNode(postorder[pend - 1]);
        if(ibegin + 1 == iend) return root;
        int p = 0;
        for( ; p < iend - ibegin; p++){
            if(inorder[ibegin + p] == postorder[pend - 1]) break;
        }
        root->left = build(inorder, ibegin, ibegin + p, postorder, pbegin, pbegin + p);
        root->right = build(inorder, ibegin + p + 1, iend, postorder, pbegin + p, pend - 1);
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder, 0, inorder.size(),
                    postorder, 0, postorder.size());
    }
};
