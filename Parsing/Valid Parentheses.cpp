/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/


class Solution {
    char left(char r){
        switch(r){
            case ')': return '(';
            case ']': return '[';
            case '}': return '{';
        }
        return 0;
    }
public:
    bool isValid(string s) {
        stack<char> w;
        for(int i = 0; i < s.length(); i++){
            switch(s[i]){
                case '(': case '{': case '[': 
                    w.push(s[i]); break;
                case ')': case '}': case ']':
                    if(w.empty() || w.top() != left(s[i])){
                        return false; 
                    }else {
                       w.pop(); break;
                    }
            }
        }
        return w.empty();
    }
};
