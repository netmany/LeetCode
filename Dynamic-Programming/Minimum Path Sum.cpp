/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size(), n = 0;
        if(m > 0) n = grid[0].size();
        if(m == 0 || n == 0) return 0;
        int* p = new int[m*n];
        p[0] = grid[0][0];
        for(int i = 1; i < m; i++){
            p[i*n] = grid[i][0] + p[(i-1)*n];
        }
        for(int j = 1; j < n; j++){
            p[j] = grid[0][j] + p[j - 1];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                p[i*n + j] = grid[i][j] + min(p[(i-1)*n+j], p[i*n+(j-1)]);
            }
        }
        int res = p[m*n - 1]; delete []p;
        return res;
    }
};
