int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size();
        int n = text2.size();

       /* if (m == 0 || n == 0)
            return 0; */

        //the dp array will store length of LCS bw text1SubStr(0->i) and text2SubStr(0->j)
        //'1' indexing followed....
        //soo  dp[m][n] will contains the LCS bw text1 and text2
        vector<vector<int>> dp(m+1, vector<int> (n+2, 0));

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {

                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;

                else
                    dp[i][j] = max (dp[i][j-1], dp[i-1][j]);

            }

        return dp[m][n];
    }
