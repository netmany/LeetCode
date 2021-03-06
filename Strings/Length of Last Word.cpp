/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/


class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int i = 0, b = 0, e = 0, len = 0;
        while(s[i] != '\0'){
            while(s[i] == ' ') i++;
            b = i;
            if(s[i] == '\0') break;
            while(s[i] != '\0' && s[i] != ' ') i++;
            e = i;
            len = e - b;
        }
        return len;
    }
};
