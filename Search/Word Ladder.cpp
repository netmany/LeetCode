/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
*/


class Solution {
    struct Node{
        int level;
        string str;
        Node(int l, string s): level(l), str(s) {}
    };
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(dict.find(end) == dict.end()) dict.insert(end);
        queue<Node> q; q.push(Node(1, start));
        while(!q.empty()){
            Node t = q.front(); q.pop();
            if(t.str == end) return t.level;
            unordered_set<string>::iterator it;
            for(int i = 0; i < t.str.length(); i++){
                char c = t.str[i];
                for(char j = 'a'; j <= 'z'; j++){
                    if(c == j) continue;
                    t.str[i] = j;
                    it = dict.find(t.str);
                    if( it != dict.end()){
                        q.push(Node(1 + t.level, t.str));
                        dict.erase(it);
                    }
                }
                t.str[i] = c;
            }
        }
        return 0;
    }
};
