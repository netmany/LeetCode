/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

//----------------------------------------------------------------------------------------
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    UndirectedGraphNode *clone(UndirectedGraphNode *node, 
        map<UndirectedGraphNode *, UndirectedGraphNode*> &m){
        if(m.count(node) == 0) {
            UndirectedGraphNode * t = new UndirectedGraphNode(node->label);
            m[node] = t;
            for(int i = 0; i < node->neighbors.size(); i++){
                t->neighbors.push_back(clone(node->neighbors[i], m));
            }
        }
        return m[node];
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        map<UndirectedGraphNode *, UndirectedGraphNode*> m;
        return clone(node, m);
    }
};
