/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/


class Solution {
    int maxHist(vector<int> &height){
        int area = 0;
        int last_height = 0, last_width = 0;
        for(int j = 0; j < height.size(); j++){
            area = max(max(area, height[j]), (last_width + 1)* min(height[j], last_height));
            last_height = last_width == 0 ? height[j] : min(last_height, height[j]);
            last_width = last_height == 0 ? 0 : last_width + 1;
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        vector<int> height(matrix[0].size(), 0);
        int area = 0;
        for(int row = 0; row < matrix.size(); row++){
            for(int i = 0; i < height.size(); i++){
                height[i] = matrix[row][i] == '0' ? 0 : 1 + height[i];
            }
            area = max(area, maxHist(height));
        }
        return area;
    }
};
