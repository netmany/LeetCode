/*
Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/


class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length(), res = 0, begin = -1;
        stack<int> stk;
        for(int i = 0; i < len; i++){
            if(s[i] == '(') stk.push(i);
            else {
                if(stk.empty()) {
                    begin = i;
                } else {
                    stk.pop();
                    if(stk.empty()) res = max(res, i - begin);
                    else res = max(res, i - stk.top());
                }
            }
        }
        return res;
    }
};
