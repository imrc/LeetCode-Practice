    /*

    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.



Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

    */




    int trap(vector<int>& height) {

        int len = height.size();
        int leftmax = 0;
        int rightmax = 0;

        int Lmax[len], Rmax[len];

        for(int i = 0; i < len; i++)
        {
            Lmax[i] = leftmax;

            leftmax = max(leftmax, height[i]);
        }

         for(int i = len-1; i >= 0; i--)
        {
            Rmax[i]= rightmax;

            rightmax = max(rightmax, height[i]);
        }

        int totalWater = 0;

        for(int i = 0; i < len; i++)
        {

            int h = min(Lmax[i], Rmax[i]);

           // cout << Lmax[i] << " "<< height[i] <<" "<<Rmax[i]<<endl;

            totalWater += ( height[i] > h )? 0 : (h-height[i]);
        }

        return totalWater;
    }
