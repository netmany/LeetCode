/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/

// ------------------------------------------------------------------
class Solution {
    void reverse(string &s, int begin, int end){
        for(int i = 0; i < (end - begin) / 2; i++){
            char t = s[begin + i];
            s[begin + i] = s[end - 1 - i];
            s[end - 1 - i] = t;
        }
    }
public:
    void reverseWords(string &s) {
        if(s.size() == 0) return;
        reverse(s, 0, s.size());
        int begin = 0, end = 0;
        while(begin < s.size()){
            while(begin < s.size() && s[begin] == ' ') begin++;
            end = begin;
            while(end < s.size() && s[end] != ' ') end++;
            reverse(s, begin, end);
            begin = end; 
        }
        int start = 0;
        begin = 0;
        while(begin < s.size()){
            while(begin < s.size() && s[begin] == ' ') begin++;
            if(start < begin){
                while(begin < s.size() && s[begin] != ' ') {
                    s[start++] = s[begin++];
                } 
            }else{
                while(begin < s.size() && s[begin] != ' ') begin++;
                start = begin;
            }
            if(begin < s.size()) s[start++] = s[begin++];
        }
        if(start == 0) s = "";
        char e = s[start - 1];
        if(e == ' ') s.resize(start - 1, '\0'); 
        else s.resize(start, '\0'); 
    }
}; 
