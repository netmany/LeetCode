/*
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/


class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(needle == NULL || haystack == NULL) return NULL;
        if(needle[0] == '\0') return haystack; 
        int len = 0; while(needle[len] != '\0') len++;
        int* next;
        if(len == 1) {
            next = new int[1]; next[0] = 1;
        } else {
            next = new int[len]; next[0] = 1; next[1] = 1;
            for(int i = 2; i < len; i++){
                if(needle[i - 1] == needle[i - 1 - next[i - 1]]) {
                    next[i] = next[i-1];
                } else {
                    int q = 0, d = next[i - 1] + 1;
                    while(q + d < i) {
                        while(q + d < i && needle[q] == needle[q + d]) q++;
                        if(q + d < i) { d++; q = 0;}
                    }
                    next[i] = d;
                }
            }
        } 
        char* res = NULL;
        int p = 0, j = 0; 
        while(haystack[p] != '\0'){
            while(needle[j] != '\0' && haystack[p + j] == needle[j]) j++;
            if(needle[j] == '\0') { res = haystack + p; break;}
            if(haystack[p + j] == '\0') break;
            p += next[j]; 
            if(j > 0) j -= next[j]; 
        }
        delete []next;
        return res;
    }
};
