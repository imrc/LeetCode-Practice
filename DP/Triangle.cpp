/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.



Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

*/

int minimumTotal(vector<vector<int>>& triangle) {

        ///for bottom up soln we start from bottom
        // And we use same input array as DP array
        int numRows = triangle.size();

        //we start from 2nd last row //since we are starting from last row
        for(int i = numRows-2; i>=0; i--)
        {
            //updating dp array left to right
            for(int j = 0; j <= i; j++)
            {
                triangle[i][j] = triangle[i][j] + min (triangle[i+1][j], triangle[i+1][j+1]);
            }

        }

        //Soo now Top of the triangle contains min_path_sum;
        return triangle[0][0];

    }
    /* Memoization soln beats 97%
    int getMin(vector<vector<int>>& triangle, int path, int currRow, int rowNum,         vector<vector<int>>& dp)
    {
        if(currRow == rowNum)//
            return 0;

        if(dp[path][currRow] != INT_MAX)
            return dp[path][currRow];


        int min_path_sum = triangle[currRow][path]

                                    //moving to i
                            + min ( getMin(triangle, path, currRow+1, rowNum, dp),

                                    //moving to i+1
                                    getMin(triangle, path+1, currRow+1, rowNum, dp) );

        dp[path][currRow] = min_path_sum;

        return min_path_sum;
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int numRows = triangle.size();

        //memoization dp
        vector<vector<int>> dp (numRows, vector<int> (numRows, INT_MAX));

        return getMin(triangle, 0, 0, numRows, dp);

    } */
