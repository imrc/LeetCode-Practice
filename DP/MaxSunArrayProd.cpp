int maxProduct(vector<int>& nums) {

        //intuition from mzchen's soln -- refer mzchen
        int max_pro = nums[0];
        int min_pro = nums[0];

        int max_pro_final = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < 0)
                swap(max_pro, min_pro);//handles case when even and odd no. of neg comes

            // 'max' for handling cases where prev num was zero
            max_pro = max (nums[i], max_pro*nums[i]);
            min_pro = min (nums[i], min_pro*nums[i]);

            max_pro_final = max (max_pro_final, max_pro);
        }

        return max_pro_final;
    }
