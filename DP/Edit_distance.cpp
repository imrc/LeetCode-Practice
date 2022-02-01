/*

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character


Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/
int minDistance(string word1, string word2) {

        int m = word1.length();
        int n = word2.length();

        ///this dp array stores the minDistance bw word1SubStr(0->i) and word2SubStr(0->j)
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        ///if word1.length == 0 then word2.length chars should be inserted
        for(int j = 0; j <= n; j++)
            dp[0][j] = j;

        ///if word2.length == 0 then word1.length chars should be deleted
        for(int i = 0; i <= m; i++)
            dp[i][0] = i;

        //calculating and filling remaining minDistance bw sub strs
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                if(word1[i-1] == word2[j-1])//matching soo no new operations required
                {
                    //saving operations done soo far
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {///not matching case --- we need to do either of 3 ops .. which ever give min

                    dp[i][j] = 1 + //considering either 3 ops is performed
                                min (
                                                dp[i][j-1],  //insertion op
                                        min(    dp[i-1][j],  //deletiom  op
                                                dp[i-1][j-1] //replacement op
                                           )
                                        );

                }


            }

        return dp[m][n];

    }
