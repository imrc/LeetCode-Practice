int maxSubArray(vector<int>& nums) {

        //kadane's algorithm

        int max_sum = INT_MIN;
        int max_sum_so_far = 0;

        for(int& elem: nums)
        {

            max_sum_so_far += elem;

            max_sum = max (max_sum, max_sum_so_far);

            if(max_sum_so_far < 0)
            {
                max_sum_so_far = 0;
            }

        }


        return max_sum;
    }
