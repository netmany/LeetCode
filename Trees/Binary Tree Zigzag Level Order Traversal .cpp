/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
        TreeNode* n;
        int level;
        Node(TreeNode* _n, int l) : n(_n), level(l) {}
    };
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if(root == NULL) return res;
        vector<int> v; 
        queue<Node> q; q.push(Node(root, 0));
        int pre_level = 0; bool toLeft = true;
        while(!q.empty()){
            Node p = q.front(); q.pop();
            if(p.level == pre_level){
                if(toLeft) v.push_back(p.n->val);
                else v.insert(v.begin(), p.n->val);
            }else{
                pre_level = p.level;
                res.push_back(v); v.clear(); v.push_back(p.n->val); 
                toLeft = !toLeft;
            }
            if(p.n->left) q.push(Node(p.n->left, p.level + 1));
            if(p.n->right) q.push(Node(p.n->right, p.level + 1));
        }
        res.push_back(v);
        return res;
    }
};
