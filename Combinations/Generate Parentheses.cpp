/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> pre = generateParenthesis(n-1);
        for(int i = 0; i < pre.size(); i++){
            z.push_back("("+pre[i]+")");
        }
        for(int i = 1; i < n-1; i++){
            vector<string> left = generateParenthesis(i);
            vector<string> right = generateParenthesis(n-i);
            for(int j = 0; j < left.size(); j++)
                for(int k = 0; k < right.size(); k++){
                    z.push_back(left[j]+right[k]);
                }
        }
    }
};
