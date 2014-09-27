/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    struct Node {
        TreeNode* p;
        int level;
        Node(TreeNode* _p, int l) : p(_p), level(l){}
    };

public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> >  res;
        queue<Node*> q;
        if(root != NULL) q.push(new Node(root, 0));
        int pre_level = -1;
        while (!q.empty()) {
            Node* n = q.front();  q.pop();
            if(n->level != pre_level){
                 pre_level = n->level;
                 vector<int> nv; nv.push_back(n->p->val);
                 res.insert(res.begin(), nv);
            } else {
                 res[0].push_back(n->p->val);
            }
            if (n->p->left != NULL) {
                 q.push(new Node(n->p->left, n->level + 1));
            }
            if (n->p->right != NULL) {
                 q.push(new Node(n->p->right, n->level + 1));
            }
        }
        return res;
    }
};
