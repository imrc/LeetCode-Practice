/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.



Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
*/

int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1,INT_MAX);

        //if amnt = 0 -> zero coins required
        dp[0] = 0;

        for(int i = 1; i <= amount; i++)
           {

               for(int j = 0; j < coins.size(); j++)
               {
                   if(i-coins[j] >= 0)
                   {
                       int curr_cnt = dp[i-coins[j]];

                       if(curr_cnt != INT_MAX)
                           dp[i] = min (dp[i], curr_cnt+1);

                   }



               }

           }

            if(dp[amount] != INT_MAX)
               return dp[amount];
            else
                return -1;
    }
