/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/


class Solution {
public:
    string minWindow(string S, string T) {
        map<char, int> m, v;
        for(int i = 0; i < T.length(); i++){
            m[T[i]]++;
        }
        int begin = 0, minLen = INT_MAX, found = 0;
        string res = "";
        for(int i = 0; i < S.length(); i++){
            if(m[S[i]] == 0){
                if(S[i] == S[begin]) begin++;
            } else {
                v[S[i]]++;
                if(v[S[i]] <= m[S[i]]) found++;
                if(v[S[i]] > m[S[i]] && S[i] == S[begin]) {
                    while(begin < i) {
                        if (m[S[begin]] < v[S[begin]]){
                            v[S[begin]]--; begin++;
                        } else if(m[S[begin]] == 0) {
                            begin++;
                        } else { 
                            break;
                        }
                    }
                }
                if(found == T.length()){
                    if(i - begin < minLen){
                        minLen = i - begin + 1;
                        res = S.substr(begin, minLen);
                    }
                }
            }
        }
        return res;
    }
};
