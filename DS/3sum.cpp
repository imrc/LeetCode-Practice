/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
*/

vector<vector<int>> threeSum(vector<int>& nums) {

        ///variation of 2sum
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i != 0 && nums[i] == nums[i-1])
                continue;

            int targetSum = -nums[i]; ///here we can do 2sum
            int low = i + 1 , high = nums.size()-1;

            while(low < high)
            {
                int sum = nums[low] + nums[high];

                if(sum == targetSum)
                {
                    vector<int> curr;
                    curr.push_back(nums[i]);
                    curr.push_back(nums[low]);
                    curr.push_back(nums[high]);

                    if(res.size() == 0)
                        res.push_back(curr);
                    else if(curr != res.back())
                        res.push_back(curr);

                    high--;low++;
                }
                else if(sum > targetSum)
                    high --;
                else
                    low++;

            }

        }

        ///output triplets should be in sorted
        return res;
    }
