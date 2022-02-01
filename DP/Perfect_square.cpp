/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.



Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
*/
int numSquares(int n) {

        ///variation of rod cutting problem
        int max_ps_num = sqrt(n);//floor of sqrt(n)

        vector<int> sqs(max_ps_num+1);

        for(int i = 0; i < max_ps_num; i++)
            sqs[i] = (i+1)*(i+1);

        vector< int> dp(n+1);

        for(int i = 1; i<=n; i++)
        {
            dp[i] = INT_MAX;
            for(int j = 0; j < max_ps_num; j++)
            {
                if(i-sqs[j] >= 0) dp[i] = min(dp[i], dp[i-sqs[j]]);

            }

            if(dp[i] != INT_MAX)
                dp[i] = dp[i] + 1;

        }
        return dp[n];
    }
