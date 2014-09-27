/*
Write a function to find the longest common prefix string amongst an array of strings.
*/


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 1) return strs[0];
        sort(strs.begin(), strs.end());
        string prefix;
        int minlen = INT_MAX, len = 0;
        for(int i = 1; i < strs.size(); i++){
            len = min(strs[i].length(), strs[i - 1].length());
            int j = 1;
            while(j <= len && strs[i].substr(0, j) == strs[i - 1].substr(0, j)) j++;
            if(j - 1 < minlen){
                minlen = j - 1;
                prefix = strs[i].substr(0, j - 1);
            }
        }
        return prefix;
    }
};
