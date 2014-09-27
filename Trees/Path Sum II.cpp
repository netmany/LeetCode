/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    void helper(vector<vector<int> >& res, vector<int> path, TreeNode *root, int sum){
        if(root == NULL) return;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(root->val == sum) res.push_back(path);
        }
        if(root->left != NULL) helper(res, path, root->left, sum - root->val);
        if(root->right != NULL) helper(res, path, root->right, sum - root->val);
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> path;
        helper(res, path, root, sum);
        return res;
    }
};
