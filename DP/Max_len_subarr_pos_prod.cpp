
/*
Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.



Example 1:

Input: nums = [1,-2,-3,4]
Output: 4
Explanation: The array nums already has a positive product of 24.

*/

int getMaxLen(vector<int>& nums) {

        int max_len = 0;
        int sub_arr_begin = 0;
        int sub_arr_neg_begin = -1;
        int sub_arr_neg_count = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0) //reset the sub_array
            {
                sub_arr_begin = i+1;
                sub_arr_neg_begin = -1;
                sub_arr_neg_count = 0;
                continue;
            }
            else if (nums[i] < 0)
            {
                sub_arr_neg_count++;

                if(sub_arr_neg_begin == -1)//first neg in sub_array
                    sub_arr_neg_begin = i;

                int tmp_max;
                    if(sub_arr_neg_count%2 == 0)//odd count of negs->positive prod
                        tmp_max = max (max_len, (i - sub_arr_begin + 1));
                    else
                        ///max will be either excluding last neg or excluding first neg
                        tmp_max = max ((i - sub_arr_begin) ,(i - sub_arr_neg_begin));

                max_len = max (max_len, tmp_max);
            }
            else//num > 0
            {
                 if(sub_arr_neg_count%2 == 0)//odd count of negs---> positive prod
                        max_len = max (max_len, (i - sub_arr_begin + 1));
                 else
                        ///max will be either excluding last neg to this index or prev max

                        max_len = max (max_len, (i - sub_arr_neg_begin));
            }
            //cout << max_len<<" ";
        }
        //cout<<endl;
        return max_len;



    }
