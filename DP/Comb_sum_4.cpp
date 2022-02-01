/*

Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.



Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
*/

int combinationSum4(vector<int>& nums, int target) {

        ///variation of coin change combinations //should do Comb Sum I,II,III before this
        int len = nums.size();

        vector<uint> dp(target+1, 0);/// uint vs int

        dp[0] =  1; ///if target = 0, no. of comb  = 1

        for(int i = 1; i <= target; i++)
            for(int j = 0; j < len; j++)
            {
                if(i - nums[j] >= 0)
                    dp[i] += dp[i-nums[j]];/// adds up all the comb of  coins adds to target
            }

        return dp[target];
    }
