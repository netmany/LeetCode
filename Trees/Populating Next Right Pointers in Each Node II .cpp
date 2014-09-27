/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    struct Node{
        int level;
        TreeLinkNode *p;
        Node(int l, TreeLinkNode *_p): level(l), p(_p) {}
    };
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        queue<Node> q;
        q.push(Node(1, root)); 
        int cur_level = 0;
        TreeLinkNode *prev = NULL;
        while(!q.empty()) {
            Node n = q.front(); q.pop();
            if(n.level == cur_level) {
                prev->next = n.p; prev = prev->next;
                if(n.p->left) q.push(Node(n.level + 1, n.p->left));
                if(n.p->right) q.push(Node(n.level + 1, n.p->right));
            } else {
                cur_level = n.level;
                prev = n.p;
                if(n.p->left) q.push(Node(n.level + 1, n.p->left));
                if(n.p->right) q.push(Node(n.level + 1, n.p->right));
            }
        }
    }
};
