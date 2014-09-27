/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/


class Solution {
    bool isAlpha(char c){
        return 'a'<= c && c <='z' ||
            'A' <= c && c <= 'Z' ||
            '0' <= c && c <= '9';
    }
    bool isEq(char a, char b){
        if(isAlpha(a) && isAlpha(b)){
            return (a < 'a'? a : a - 'a' +'A') ==
                   (b < 'a'? b : b - 'a' +'A');
        }
        return false;
    }
public:
    bool isPalindrome(string s) {
        if(s.length() == 0) return true;
        int begin = 0, end = s.length() -1;
        do{
            while(begin < end && !isAlpha(s[begin])) begin++;
            while(begin < end && !isAlpha(s[end])) end--;
            while(begin < end && isEq(s[begin], s[end])){
                begin++; end--;
            }
        }while(begin < end && !(isAlpha(s[begin]) && isAlpha(s[end])));
        return begin >= end;
    }
};
