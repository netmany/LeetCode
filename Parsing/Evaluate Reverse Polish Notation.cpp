/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        int op1, op2;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                op2 = s.top(); s.pop();
                op1 = s.top(); s.pop();
                s.push(op1 + op2);
            }else if(tokens[i] == "-"){
                op2 = s.top(); s.pop();
                op1 = s.top(); s.pop();
                s.push(op1 - op2);
            }else if(tokens[i] == "*"){
                op2 = s.top(); s.pop();
                op1 = s.top(); s.pop();
                s.push(op1 * op2);
            }else if(tokens[i] == "/"){
                op2 = s.top(); s.pop();
                op1 = s.top(); s.pop();
                s.push(op1 / op2);
            }else {
                s.push(atoi(tokens[i].c_str()));
            }
        }
        return s.top();
    }
};
