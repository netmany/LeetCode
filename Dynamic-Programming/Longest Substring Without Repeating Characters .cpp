/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        map<char, int> m;
        int begin = 0, end = 0, len = INT_MIN;
        int i = 0;
        for(; i < s.length(); i++){
            if(m.count(s[i]) != 0){
                len = max(len, i - begin);
                int t = m[s[i]];
                for(int j = begin; j <= t; j++) m.erase(s[j]);
                begin = t + 1;
            }
            m[s[i]] = i;
        }
        len = max(len, i - begin);
        return len;
    }
};
