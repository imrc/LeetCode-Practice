/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.



Example 1:


Input: m = 3, n = 7
Output: 28
*/

int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));

        //only one way to go any pos on just right side from 0,0
        for(int j = 0;  j < n; j++)
            dp[0][j] = 1;

        //only one way to go any pos on just bottom side 0,0
        for(int i = 0; i < m; i++)
            dp[i][0] = 1;

        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
            {
                //no.ways = no.ways from left + no. of ways from top
                dp[i][j] = dp[i][j-1] + dp[i-1][j];

            }

            return dp[m-1][n-1];

    }
