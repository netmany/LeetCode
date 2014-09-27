/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/


class Solution {
    int maxHist(vector<int> &height){
        int area = 0;
        height.push_back(0);
        stack<int> s;
        int i = 0;
        while(i < height.size()){
            if(s.empty() || height[i] >= height[s.top()]){
                s.push(i++);
            } else {
                int j = s.top(); s.pop();
                area = max(area, height[j] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        height.pop_back();
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
