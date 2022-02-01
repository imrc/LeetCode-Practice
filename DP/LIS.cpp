/*

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].



Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

int getCeil(vector<int>& tailA, int num)
    {
        int low = 0, high = tailA.size()-1;

        while(low < high)
        {
            int mid = low + (high - low)/2;

            if(tailA[mid] >= num)
                high = mid;
            else
                low = mid+1;
        }
        return high;
    }


    int lengthOfLIS(vector<int>& nums) {

       int total_num = nums.size();

        vector<int> tail_array;

        tail_array.push_back(nums[0]);

        for(int i = 1;  i < total_num; i++)
        {
            if(nums[i] > tail_array.back())
                tail_array.push_back(nums[i]);

            else
            {
                int ceil_idx = getCeil(tail_array, nums[i]);
                tail_array[ceil_idx] = nums[i];
            }

        }

        return tail_array.size();
        /*//Slower O(n^2) soln


        //this dp[i] in array stores - LIS ending at 'i'th elem in nums
        vector<int> dp(total_num);

        dp[0] = 1;//LIS ending at the 1st index will be one , LIS is that elem alone itself

        for(int i = 1; i < total_num; i++)
        {
            dp[i] = 1;//initialized as one bcz LIS by considering ith elem alone will give 1

            ///iterate all the elements before and see wheather any elem is smaller than this elem
            for(int j = 0; j<i; j++)
            {
                if(nums[j] < nums[i])//if there is a smaller element , then LIS ending at i will be LIS ending at that elem + 1(considering this elem)
                    ///but there can be more than one smaller elem before we take the one with max LIS
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }

            }


        }

        //LIS of the whole array will be the max element in the dp array
        //(bcz we dont know LIS ending at which index will be the biggest)
        int max_LIS = *max_element(dp.begin(), dp.end());

        return max_LIS; */
    }
