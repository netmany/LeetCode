/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode *ArrayToBST(vector<int> &num, int begin, int end){
        if(begin < end){
            int mid = (begin + end) / 2;
            TreeNode* res = new TreeNode(num[mid]);
            res->left = ArrayToBST(num, begin, mid);
            res->right = ArrayToBST(num, mid + 1, end);
            return res;
        }else
            return NULL;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return ArrayToBST(num, 0, num.size());
    }
};
