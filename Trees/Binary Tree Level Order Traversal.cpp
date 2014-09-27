/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    struct Node{
        TreeNode *n;
        int level;
        Node(TreeNode *_n, int _level) : n(_n), level(_level){}
    };
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<Node> q;
        vector<vector<int> > res;
        if(root == NULL) return res;
        q.push(Node(root, 0));
        int cur_level = -1;
        while(!q.empty()){
            Node p = q.front(); q.pop();
            if(p.n->left != NULL) q.push(Node(p.n->left, p.level + 1));
            if(p.n->right != NULL) q.push(Node(p.n->right, p.level + 1));
            if(p.level != cur_level){
                cur_level = p.level;
                vector<int> t; t.push_back(p.n->val);
                res.push_back(t);
            }else{
                res[cur_level].push_back(p.n->val);
            }
        }
        return res;
    }
};
