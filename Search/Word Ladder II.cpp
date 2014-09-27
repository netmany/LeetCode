/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
*/


class Solution {
    void outputPath(vector<vector<string>> &res, vector<string> &path,
        unordered_map<string, vector<string> > &reverseLink, string end){
        if(reverseLink[end].size() == 0){
            vector<string> tmp = path;
            reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
        } else {
            vector<string>::iterator it;
            for(it = reverseLink[end].begin(); it != reverseLink[end].end(); it++){
                path.push_back(*it);
                outputPath(res, path, reverseLink, *it);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, vector<string> > reverseLink;
        if(dict.find(end) == dict.end()) dict.insert(end);
        unordered_set<string> layer[2];
        layer[0].insert(start);
        int cur = 0, next = 1, len = start.length();
        while(!layer[cur].empty()){
            if(reverseLink.find(end) != reverseLink.end()) break;
            unordered_set<string>::iterator it;
            for(it = layer[cur].begin(); it != layer[cur].end(); it++){
                dict.erase(*it);
            }
            layer[next].clear();
            for(it = layer[cur].begin(); it != layer[cur].end(); it++){
                string p = *it;
                for(int j = 0; j < len; j++){
                    char c = p[j];
                    for(char k = 'a'; k <= 'z'; k++){
                        if(c == k) continue;
                        p[j] = k;
                        if(dict.find(p) != dict.end()){
                            layer[next].insert(p);
                            reverseLink[p].push_back(*it);
                        }
                    }
                    p[j] = c;
                }
            }
            cur = !cur; next = !next;
        }
        vector<vector<string>> res;
        if(reverseLink.find(end) == reverseLink.end()) return res;
        vector<string> path; path.push_back(end);
        outputPath(res, path, reverseLink, end);
        return res;
    }
};
