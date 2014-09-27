/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) 
            return 0;
        vector<vector<int> > p(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        p[0][0] = ! obstacleGrid[0][0];
        for(int i = 0; i < obstacleGrid.size(); i++){
            for(int j = 0; j < obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j] == 0) {
                    if(i > 0 && j > 0){
                        if(obstacleGrid[i][j - 1] == 0) p[i][j] += p[i][j - 1];
                        if(obstacleGrid[i - 1][j] == 0) p[i][j] += p[i - 1][j];
                    } else {
                        if(i == 0 && j > 0 && obstacleGrid[i][j - 1] == 0) p[i][j] = p[i][j - 1];
                        if(i > 0 && j == 0 && obstacleGrid[i - 1][j] == 0) p[i][j] = p[i - 1][j];
                    }
                }
            }
        }
        return p[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
