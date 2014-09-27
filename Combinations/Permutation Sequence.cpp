/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/


class Solution {
public:
    string getPermutation(int n, int k) {
        int p = 1;
        vector<int> v(n, 1);
        vector<int> q(n);
        string res(n,'1');
        for(int i = 0; i < n; i++){
            if(i > 0) v[i] = v[i - 1] * i;
            q[i] = i + 1;
        }
        int j = 1;
        while(j < n){
            p = k / v[n-j] + (k % v[n-j] == 0 ? 0 : 1);
            res[j-1] = q[p - 1] - 1 + '1';
            q.erase(q.begin() + p - 1);
            k = k % v[n-j];
            k = (k == 0) ? v[n-j] : k;
            j++;
        }
        res[n-1] = q[0] - 1 + '1';
        return res;
    }
};
