/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/


class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return;
        vector<int> row(matrix.size(), 0), col(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    row[i] = 1; col[j] = 1;
                }
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(row[i] == 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
