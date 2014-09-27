/*
Determine whether an integer is a palindrome. Do this without extra space.
*/


class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0) return true;
        if(x < 0) return false;
        vector<char> v;
        while(x){
            v.push_back(x % 10);
            x /= 10;
        }
        for(int i = 0; i < v.size() / 2; i++){
            if(v[i] != v[v.size() - 1- i]) return false;
        }
        return true;
    }
};
