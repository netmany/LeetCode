/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/


class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        while(i<n){
            if(A[i] == elem){
                int j = i+1;
                while(j<n && A[j] == elem) j++;
                if(j<n) {
                    A[i] = A[j];
                    A[j] = elem;
                } else {
                  break;
                }
            }
            i++;
        }
        return i;
    }
};
