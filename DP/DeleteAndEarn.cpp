int deleteAndEarn(vector<int>& nums)
   {

        int maxElem = *max_element(nums.begin(), nums.end());

        vector<int> bucketSum(maxElem + 1);

        for(int& elem: nums)
        {
            bucketSum[elem] += elem;
        }

       ///After creating bucketSum Array this a HouseRobber I problem on that array

        int dele_i = 0; int keep_i = 0;
        for(int i = 1; i <= maxElem; i++)
        {
            int prev_dele_i = dele_i;

            dele_i = keep_i + bucketSum[i];

            keep_i = max (keep_i, prev_dele_i);

        }

        return max (dele_i, keep_i);


    }
