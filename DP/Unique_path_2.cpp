/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.



Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int> > dp(m, vector<int>(n));

        //only 1 way to go any pos just below until an obstacle found//after obstacle 0 way
        for(int i = 0; i <m; i++)
        {
            if(obstacleGrid[i][0] == 1)
                break;

            dp[i][0] = 1;
        }

        //only 1 way to go any pos just right until an obstacle found//after obstacle 0 way
        for(int j = 0; j <n; j++)
        {
            if(obstacleGrid[0][j] == 1)
                break;

            dp[0][j] = 1;
        }

        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                {
                    int ways_from_left = dp[i][j-1];
                    int ways_from_top  = dp[i-1][j];
                    /*
                    //if there is obstacle left
                    if(obstacleGrid[i][j-1] == 1)
                        ways_from_left = 0;

                    //if there is obstacle top
                    if(obstacleGrid[i-1][j] == 1)
                        ways_from_top = 0; */

                    dp[i][j] = ways_from_left + ways_from_top;

                }


            }

        return dp[m-1][n-1];

    }
