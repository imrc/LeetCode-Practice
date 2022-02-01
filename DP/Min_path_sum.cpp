/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.



Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
*/

int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();


        for(int i = 0; i < m; i++)
            for(int j = 0; j < n ; j++)
            {

                if(i != 0 && j != 0)
                     //min of left and top value
                    grid[i][j] = grid[i][j] + min (grid[i][j-1], grid[i-1][j]);

                else if (i == 0 && j != 0)//first row
                    grid[i][j] = grid[i][j] + grid[i][j-1];//left value

                else if (j == 0 && i != 0)//first column
                    grid[i][j] = grid[i][j] + grid[i-1][j];//top value

                else
                    continue;
            }

        return grid[m-1][n-1];
    }
