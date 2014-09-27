/*
Given preorder and inorder traversal of a tree, construct the binary tree.
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
    TreeNode *build(vector<int> &preorder, int pbegin, int pend,
            vector<int> &inorder, int ibegin, int iend) {
        if(pbegin == pend) return NULL;
        TreeNode *root = new TreeNode(preorder[pbegin]);
        if(pbegin + 1 == pend) return root;
        int p = 0;
        for( ; p < iend - ibegin; p++){
            if(inorder[ibegin + p] == preorder[pbegin]) break;
        }
        root->left = build(preorder, pbegin + 1, pbegin +1 + p, inorder, ibegin, ibegin + p);
        root->right = build(preorder, pbegin + 1 + p, pend, inorder, ibegin + p + 1, iend);
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder, 0, preorder.size(),
                    inorder, 0, inorder.size());
    }
};
