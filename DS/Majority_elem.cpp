/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
*/
int majorityElement(vector<int>& nums) {

        int curr_mj = nums[0];
        int curr_cnt = 1;

        for(int i = 1; i < nums.size(); i++)
        {
            if(curr_cnt == 0)
            {
                curr_mj = nums[i];
                curr_cnt = 1;
            }
            else if(nums[i] == curr_mj)
                curr_cnt ++;
            else
                curr_cnt--;

        }
        //since majority elem occupies more than half of the nums .. curr_cnt will be > 0 at the end
        return curr_mj;
    }
