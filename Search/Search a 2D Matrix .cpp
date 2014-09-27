/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int left = 0, right = matrix.size() - 1;
        if(right < 0) return false;
        int m1, m2;
        while(left <= right){
            m1 = (left + right) / 2;
            if (matrix[m1][0] == target){
                return true;
            }else if (matrix[m1][0] < target){
                left = m1 + 1;
            }else {
                right = m1 - 1;
            }
        }
        if(matrix[m1][0] > target){
            if (m1 == 0) return false;
            m1--;
        }
        left = 0; right = matrix[m1].size() - 1;
        while(left <= right){
            m2 = (left + right) / 2;
            if (matrix[m1][m2] == target){
                return true;
            }else if (matrix[m1][m2] < target){
                left = m2 + 1;
            }else {
                right = m2 - 1;
            }
        }
        return false;
    }
};
