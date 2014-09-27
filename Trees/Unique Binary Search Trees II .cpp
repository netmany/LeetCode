/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    void generate(vector<TreeNode *> &res, vector<int> &v, int begin, int end){
        if(begin == end) {
            res.push_back(NULL);
            return;
        }
        for(int i = begin; i < end; i++){
            vector<TreeNode *> left, right;
            generate(left, v, begin, i);
            generate(right, v, i + 1, end);
            for(int j = 0; j < left.size(); j++){
                for(int k = 0; k <right.size(); k++){
                    TreeNode* t = new TreeNode(v[i]);
                    t->left = left[j]; t->right = right[k];
                    res.push_back(t);
                }
            }
        }
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            v[i] = i + 1;
        }
        vector<TreeNode *> res;
        generate(res, v, 0, n);
        return res;
    }
};
