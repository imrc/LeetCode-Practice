int maxSubarraySumCircular(vector<int>& nums) {

        //kadan's algorithm
        //From lee's solution
        //max_sum_sub_arr =  total_sum - min_sum_sub_arr;

        int total_sum = 0;

        int min_sum = INT_MAX;
        int min_sum_so_far = 0;

        int max_sum = INT_MIN;
        int max_sum_so_far = 0;

        for(int& elem: nums)
        {
            total_sum += elem;

            min_sum_so_far += elem;
            min_sum = min (min_sum, min_sum_so_far);
            if(min_sum_so_far > 0)
            {
                min_sum_so_far = 0;
            }

            max_sum_so_far += elem;
            max_sum = max (max_sum, max_sum_so_far);
            if(max_sum_so_far < 0)
            {
                max_sum_so_far = 0;
            }

        }
        int max_sum_sub_arr;

        if(max_sum > 0)
            max_sum_sub_arr =  max (max_sum, (total_sum - min_sum));
        else
            max_sum_sub_arr = max_sum;

        return max_sum_sub_arr;
    }
