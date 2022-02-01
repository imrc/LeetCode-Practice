/*
A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.



Example 1:

Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).
*/

int wiggleMaxLength(vector<int>& nums) {

        ///efficient soln O(n)
        int len = nums.size();

        if(len == 1) return 1;

        int up = 1; //max_len_subseq when last diff was +ve
        int down = 1;//max_len_subseq when last diff was -ve

        int diff ;

        for(int i = 0; i < len-1; i++)
        {
            diff = nums[i+1] - nums[i];

            if(diff > 0)
                up = down + 1;

            else if (diff < 0)
                down = up + 1;

        }

        return max ( up, down);

        /* little slow O(n^2) soln
        //LIS variation

        //stores maxWseqLen ending at i in dp[i] sign of len stored will represent wheather prev diff was +ve or negative
        vector<int> dp(len);

        dp[0] = 1;

        for(int i = 1; i < len; i++)
        {
            dp[i] = 1;
            for(int j = 0; j<i; j++)
            {

                if(nums[i] != nums[j]) //not same element
                {
                    bool neg = (nums[i] < nums[j]);

                    if(dp[j] == 1 )
                    {
                        if (dp[i] != 1)
                            continue;

                        if(!neg)
                            dp[i] = 2;
                        else
                            dp[i] = -2;
                    }
                    else
                    {
                        if(dp[j] > 0) //prev diff was +ve
                        {
                            if(neg)
                                dp[i] = -(max ( abs(dp[i]), dp[j] + 1) );
                        }

                        else//prev diff was -ve
                        {
                            if(!neg)
                                dp[i] = (max (abs(dp[i]), abs(dp[j]) + 1));
                        }
                    }
                }
            }
        }

        int max_len = 0;
        for(int& x: dp)
            max_len = max(max_len, abs(x));

        return max_len; */
    }
