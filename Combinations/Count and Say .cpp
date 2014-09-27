/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.
*/


class Solution {
    string int2str(int n){
        int i = n;
        string str;
        while(i){
            str = string(1, i % 10 + '0') + str;
            i /= 10;
        }
        return str;
    }
    string update(string str){
        string res;
        int p = 0, i;
        while(p < str.length()){
            i = p;
            while(i < str.length() && str[i] == str[p]) i++;
            res += int2str(i-p) + string(1, str[p]);
            p = i;
        }
        return res;
    }
public:
    string countAndSay(int n) {
        string str = int2str(1);
        int i = n - 1;
        while (i > 0){
            str = update (str);
            i--;
        }
        return str;
    }
};
