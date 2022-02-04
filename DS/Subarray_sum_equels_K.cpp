/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.



Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
*/
int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> pref;//there can be more than one contigous arrays with same sum since '0' comes it will be new subarray but with same sum

        int sub_cnt = 0;
        int pref_sum = 0;
        pref[0] = 1; // to handle cases like k = nums[i]
        for(int i = 0; i < nums.size(); i++)
        {
            //if any sub array ending with nums[i] sums k then curr_pref-k will be in hashset with num of occurrences (if elem 0 are in bw more than one subArray will be there ending with nums[i])
            pref_sum += nums[i];
            if(pref.count(pref_sum-k) == 1)
            {
                sub_cnt += pref[pref_sum-k];
            }

        pref[pref_sum]++;

        }

        return sub_cnt;

    }
