/*

An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.



Example 1:

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

*/



int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size();

        //faster soln
        if(len < 3)
            return 0;

        //stores um of arithemetic slices ending with curr_pos
        vector<int> dp(len,0);

        if((nums[2]-nums[1]) == (nums[1] - nums[0]))
           dp[2] = 1;

        int total_substr = dp[2];

        for(int i = 3; i < len; i++)
           {

               if ((nums[i]-nums[i-1]) == (nums[i-1] - nums[i-2]))
               {
                   dp[i] = 1 + dp [i-1];
               }

            total_substr += dp[i];

           }

        return total_substr;

        /*//Not faster soln /// but works
        int prev_diff = nums[1] - nums[0];

        int  curr_valid_substr_len = 2;

        int total_substrs = 0;


        //curr_valid_substr_len reach the max size of the substr with same diff ,if new diff comes , it first calculate and add num of possibe substrs for prev_diff


        for(int i = 1; i < len-1; i++)
        {
            cout << curr_valid_substr_len <<" " <<i<<endl;

            if((nums[i+1] - nums[i]) != prev_diff)
            {
                if(curr_valid_substr_len >= 3)
                {
                    // total substr(atleast size 3) possible for given len is
                    //    ((len - 2)*(len-1))/2

                    int num_substrs = ((curr_valid_substr_len - 2)*(curr_valid_substr_len - 1))/2;

                    total_substrs += num_substrs;
                }

                prev_diff = (nums[i+1] - nums[i]);
                curr_valid_substr_len = 2;
                continue;
            }

            curr_valid_substr_len++;
        }

        if(curr_valid_substr_len >= 3)
                {
                    // total substr(atleast size 3) possible for given len is
                    //    ((len - 2)*(len-1))/2

                    int num_substrs = ((curr_valid_substr_len - 2)*(curr_valid_substr_len - 1))/2;

                    total_substrs += num_substrs;
                }

        return total_substrs;
        */

    }
