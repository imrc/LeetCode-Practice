/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.



Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
*/

int maximalSquare(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector< vector<int>> dp (m+1, vector<int> (n+1 , 0));

        int rec = 0;
        for(int i = 1; i <=m; i++)
            for(int j = 1; j <= n; j++)
            {
                if(matrix[i-1][j-1] == '1')
                    ///if min of left,top,and diagonal are 1 means all are one
                    dp[i][j] = 1 + min (dp[i-1][j-1], min (dp[i-1][j], dp[i][j-1]));

                rec = max (rec, dp[i][j]);
            }

        return rec*rec;
    }
