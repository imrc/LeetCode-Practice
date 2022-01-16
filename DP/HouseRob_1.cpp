int rob(vector<int>& nums) {

      int totalHouses = nums.size();

      if(totalHouses == 1)
            return nums[0];

        //MCU max cash upto

      int MCU2ndLastHouse = nums [0];
      int MCULastHouse = max(nums[1], MCU2ndLastHouse);
      int MCUcurrHouse = max(MCULastHouse, MCU2ndLastHouse);



      for(int i=2; i <  totalHouses; i++)
        {
              MCUcurrHouse = max( nums[i] + MCU2ndLastHouse, MCULastHouse);
              MCU2ndLastHouse = MCULastHouse;
              MCULastHouse = MCUcurrHouse;
        }

      return MCUcurrHouse;
    }
