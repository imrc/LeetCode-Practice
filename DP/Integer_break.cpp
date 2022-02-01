/*
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.



Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
*/

int integerBreak(int n) {

        vector<int> dp(n+1);

        ///initalizing 1st 4
        switch(n)
        {
            case 4: dp[4] = 4;
            case 3: dp[3] = 2;
            case 2: dp[2] = 1;
            case 1: dp[0] = 0;
                    dp[1] = 1;
        }
        ////chunks of 2 and 3 do the magic (2,3 are the integers that closest to 'e')3 is preffered since it give the big product
        for(int i = 5; i <= n; i++)
        {
            dp[i] = 3*max (i-3, dp[i-3]);
        }

        return dp[n];

    }
