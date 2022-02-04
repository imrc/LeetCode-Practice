/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.



Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
*/
bool increasingTriplet(vector<int>& nums) {


        ////solved as variation of LIS
       vector<int> trip;
        trip.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++)
        {
            if(trip.size() >= 3)
                return true;

            if(nums[i] > trip.back())
                trip.push_back(nums[i]);
            else
            {
                int idx = getCeil(trip, nums[i]);
                trip[idx] = nums[i];
            }

        }

        if(trip.size() >= 3)
            return true;
        else
            return false;

    }

    int getCeil(vector<int>& trip, int num)
    {
        int low = 0, high = trip.size() -1;

        while(low<high)
        {
            int mid = low + (high-low)/2;
            //finding smallest midd greater than num
            if(trip[mid] >= num)
                high = mid;
            else
                low = mid+1;

        }

        return high;
    }
