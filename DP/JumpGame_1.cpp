 bool canJump(vector<int>& nums) {

        int total = nums.size();

        if (total == 1)
            return true;

        if (nums[0] == 0)
            return false;

        int minJump = 1;//min jump to reach a positon which will lead to last index

        for(int i = total - 2; i > 0; i--)
        {
                if(nums[i] >= minJump)
                {
                    minJump = 1;
                }
                else
                {
                   minJump = minJump + 1;
                }

        }

        if(nums[0] >= minJump)
            return true;
        else
            return false;


    }
