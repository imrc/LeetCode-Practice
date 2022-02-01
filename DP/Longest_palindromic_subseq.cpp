/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.



Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
*/

int longestPalindromeSubseq(string s) {
        //Variation of LCS
        int len = s.size();

        vector< vector<int> > dp(len+1, vector<int>(len+1,0));

        for(int i = 1; i <=len; i++)
            for(int j = 1; j <= len; j++)//reverse of string
            {
                if(s[i-1]==s[len-j])
                    dp[i][j] = 1 + dp[i-1][j-1];

                else
                    dp[i][j] = max (dp[i-1][j], dp[i][j-1]);

            }


        return dp[len][len];
    }
