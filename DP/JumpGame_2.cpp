bool canJump(vector<int>& nums, int start, int end) //Jump Game I solution
    {

        int total = end - start + 1;

        if (total == 1)
            return true;

        if (nums[start] == 0)
            return false;

        int minJump = 1;//min jump to reach a positon which will lead to last index

        for(int i = total - 2; i > start; i--)
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

        if(nums[start] >= minJump)
            return true;
        else
            return false;

    }

    int jumper(vector<int>& nums, int start, int end) //Driver function
    {
        //cout << start <<" "<< end<<endl;

        int total = end - start + 1;

        if (total == 1)
            return 0;


        for(int i = start ; i < total; i++)
        {
            if(nums[i] >= (total-i-1))
            {
                if(canJump(nums, start, i)) //checks if this position is reachable from start
                    return (1 + jumper(nums, start, i)); // returns min jumps reach this pos from start ,(since this pos is reachable from start)

                //If not reachable continue with next

            }


        }

        return 0;

    }

    int jump(vector<int>& nums) //Main function
    {
        return jumper(nums, 0, nums.size()-1);
    }
