/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/


class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        int p = 0, num = 1;
        for(int i = n; i > 0; i -= 2){
            for(int j = p; j < p + i; j++){
                res[p][j] = num++;
            }
            for(int j = p + 1; j < p + i; j++){
                res[j][p + i - 1] = num++;
            }
            for(int j = p + i - 2; j >= p; j--){
                res[p + i - 1][j] = num++;
            }
            for(int j = p + i - 2; j > p ; j--){
                res[j][p] = num++;
            }
            p++;
        }
        return res;
    }
};
