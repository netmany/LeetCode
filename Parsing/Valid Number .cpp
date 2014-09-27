/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
*/


class Solution {
    bool isDigit(char c){
        return c >= '0' && c <= '9' ;
    }
    
public:
    bool isNumber(const char *s) {
        if(s == NULL) return false;
        int i = 0;
        while(s[i] == ' ') i++;
        
        if(s[i] == '-' || s[i] == '+') i++;
        
        bool hasNum = false;
        
        if(isDigit(s[i])) hasNum = true;
        while(isDigit(s[i])) i++;
        
        if(s[i] == '.') i++;
        
        if(isDigit(s[i])) hasNum = true;
        while(isDigit(s[i])) i++;
        
        if (hasNum && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            if(s[i] == '-' || s[i] == '+') i++;
            hasNum = false;
        }
        
        if(isDigit(s[i])) hasNum = true;
        while(isDigit(s[i])) i++;
        
        while(s[i] == ' ') i++;
        
        if(s[i] == '\0') return hasNum;
        else return false;
    }
};
