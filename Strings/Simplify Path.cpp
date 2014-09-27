/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/


class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int q = 1, p;
        while(q < path.length()){
            while(q < path.length() && path[q] =='/') q++;
            p = q;
            while(p < path.length() && path[p]!='/') p++;
            if(p > q) {
                string temp = path.substr(q, p - q);
                if(temp == "..") { if(!s.empty()) s.pop();}
                else if(temp != ".") s.push(temp);
            }
            q = p;
        }
        string res;
        if(!s.empty()) {res = s.top(); s.pop();}
        while(!s.empty()) {
            res = s.top() + "/" + res; s.pop();
        }
        res = "/" + res;
        return res;
        
    }
};
