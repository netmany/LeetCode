/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
    map<TreeNode*, int> mp;
    int maxDep(TreeNode *root){
        if(root == NULL) return 0;
        if(mp.count(root) == 0){
            int t = max(maxDep(root->left), maxDep(root->right));
            mp[root] = t > 0 ? root->val + t : root->val;
        }
        return mp[root];
    }
    void dfs(TreeNode *root, int &m){
        if(root == NULL) return ;
        dfs(root->left, m);
        dfs(root->right, m);
        int t = root->val;
        if(maxDep(root->left) > 0) t += maxDep(root->left);
        if(maxDep(root->right) > 0) t += maxDep(root->right);
        m = max(m, t);
    }
public:
    int maxPathSum(TreeNode *root) {
        int m = INT_MIN;
        dfs(root, m);
        return m;
    }
};
