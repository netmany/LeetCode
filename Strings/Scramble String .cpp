/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/


class Solution {
    bool S(string &A, int Abegin, int Aend,
            string &B, int Bbegin, int Bend){
        if(Abegin + 1 == Aend) return A[Abegin] == B[Bbegin];
        int tbl[26] = {0};
        int offset = Bbegin - Abegin;
        for(int i = Abegin; i < Aend; i++){
            tbl[A[i] - 'a']++; 
            tbl[B[i + offset] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(tbl[i]) return false;
        }
        for(int p = 1; Abegin + p < Aend; p++){
            if(S(A, Abegin, Abegin + p, B, Bbegin, Bbegin + p) && S(A, Abegin + p, Aend, B, Bbegin + p, Bend) ||
               S(A, Abegin, Abegin + p, B, Bend - p, Bend) && S(A, Abegin + p, Aend, B, Bbegin, Bend - p)){
               return true;
            }
        }
        return false;
    }
public:
    bool isScramble(string s1, string s2) {
        return S(s1, 0, s1.length(), s2, 0, s2.length());
    }
};
