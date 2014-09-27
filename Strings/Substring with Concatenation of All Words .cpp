/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/


class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        map<string, int> m;
        for(int i = 0; i < L.size(); i++){
            if(m.count(L[i]) == 0) m[L[i]] = 1;
            else m[L[i]]++;
        }
        int sublen = L[0].length();
        int end = S.length() - sublen * L.size();
        
        for(int i = 0; i <= end; i++){
            int j = 0, p = 0;
            map<string, int> tmp;
            for(; j < L.size(); j++){
                string cur = S.substr(i + p, sublen);
                if(m.count(cur) == 0) break; 
                tmp[cur]++;
                if(tmp[cur] > m[cur]) break;
                p += sublen;
            }
            if(j == L.size()) res.push_back(i);
        }
        return res;
    }
};
