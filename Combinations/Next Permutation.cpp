/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/


class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i = num.size() -1;
        while(i-1 >= 0 && num[i] <= num[i-1]) i--;
        if(i == 0) { sort(num.begin(), num.end()); return;}
        int p = i-1; i = num.size() -1;
        while(num[i] <= num[p]) i--;
        int t = num[p]; num[p] = num[i]; num[i] = t;
        sort(num.begin() + p + 1, num.end());
    }
};
