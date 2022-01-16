class Solution {
public:


    int HouseRob(vector<int>& nums, int start, int end)
    {

      int totalHouses = end - start + 1;

      switch(totalHouses)
        {
            case 1:
                return nums[start];

            case 2:
                return max (nums[start], nums[end]);
        }

      //MCU max cash upto

      int MCU2ndLastHouse = nums [start];
      int MCULastHouse = max(nums[start + 1], MCU2ndLastHouse);
      int MCUcurrHouse = max(MCULastHouse, MCU2ndLastHouse);



      for(int i = start+2; i <=  end; i++)
        {
              MCUcurrHouse = max( nums[i] + MCU2ndLastHouse, MCULastHouse);
              MCU2ndLastHouse = MCULastHouse;
              MCULastHouse = MCUcurrHouse;
        }

      return MCUcurrHouse;
    }



    int rob(vector<int>& nums)
    {
        int totalHouses = nums.size();

        switch(totalHouses)
        {
            case 1:
                return nums[0];

            case 2:
                return max (nums[1], nums[0]);

            case 3:
                return max (nums[2], max (nums[1], nums[0]));

            default: //if First house robbed Last house cannot be robbed vice versa
                return max (HouseRob(nums, 0, totalHouses-2), HouseRob(nums, 1, totalHouses-1));

        }


    }
};
