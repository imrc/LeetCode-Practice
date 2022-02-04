/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.



Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
*/
vector<int> productExceptSelf(vector<int>& nums) {


       /* int total_prod = accumulate (nums.begin(), nums.end(),1,[&zero_cnt](int x, int y)
                                     {
                                        if(y == 0)
                                        {zero_cnt++; return 1; }
                                                else
                                             return x*y;
                                     });*/
        vector<int> res;
        int zero_cnt = 0;
        int total_prod = 1;
        int zero_idx = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
                total_prod *= nums[i];
            else
            {
                zero_cnt++;
                 if(zero_cnt > 1) //if there are more than 1 zero then At All pos prdoExcpItself will be Zero
                    {
                        res.resize(nums.size(),0);
                        return res;
                    }
                zero_idx = i;
            }

        }


        for(int i = 0; i < nums.size(); i++)
        {
            if(zero_idx == -1)///No zeros in array
            {
            int curr_prod = total_prod/nums[i]; ;
            res.push_back(curr_prod);
            }
            else
            {
                if(i == zero_idx)//at zero index only non-zero prod
                    res.push_back(total_prod);
                else
                    res.push_back(0);
            }
        }

        return res;

    }
