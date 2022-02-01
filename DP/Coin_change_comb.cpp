/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.



Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/
int change(int amount, vector<int>& coins) {

        int len = coins.size();
        vector<vector<int>> dp(amount+1,  vector<int>(len+1,0));

        ///if amount = 0 implies no.comb = 1
        for(int j = 0; j <= len; j++)
            dp[0][j] = 1;

        ///if 0 coins || 0 comb possible if amount != 0
        for(int i = 1; i <= amount; i++)
            dp[i][0] = 0;

        for(int i = 1; i <= amount; i++)
            for(int j = 1;  j <= len; j++)
            {
                if(i-coins[j-1] >= 0)
                    dp[i][j] = dp[i][j-1] + dp[i-coins[j-1]][j];
                else
                    dp[i][j] = dp[i][j-1];


            }

        return dp[amount][len];

    }
