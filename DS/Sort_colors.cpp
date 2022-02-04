/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/
void sortColors(vector<int>& nums) {

        int curr_sort_idx = 0;
        //for sorting red
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                swap(nums[i],nums[curr_sort_idx]);
                curr_sort_idx++;
            }
        }

        //for sorting white
        for(int i = curr_sort_idx; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                swap(nums[i],nums[curr_sort_idx]);
                curr_sort_idx++;
            }
        }

        //now remaining blue will be already sorted
        return;
    }
