/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if(matrix.size() == 0 || matrix[0].size() == 0) return res;
        for(int top = 0, left = 0, height = matrix.size(), width = matrix[0].size(); 
            height > 0 && width > 0; 
            top++, left++, height -=2, width -= 2){
            if(width == 1) {
                for(int i = 0; i < height; i++){
                    res.push_back(matrix[top + i][top]);
                }
                break;
            } else if(height == 1) {
                for(int i = 0; i < width; i++){
                    res.push_back(matrix[top][top + i]);
                }
                break;
            }
            for(int i = 0; i < width -1; i++){
                res.push_back(matrix[top][top + i]);
            }
            for(int i = 0; i < height -1; i++){
                res.push_back(matrix[top + i][top + width - 1]);
            }
            for(int i = 0; i < width -1; i++){
                res.push_back(matrix[top + height - 1][top + width - 1 - i]);
            }
            for(int i = 0; i < height -1; i++){
                res.push_back(matrix[top + height - 1 - i][top]);
            }
            
        }
        return res;
    }
};
