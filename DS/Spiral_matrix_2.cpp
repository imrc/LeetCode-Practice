/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.



Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
*/

 vector<vector<int>> generateMatrix(int n) {

        vector<vector<int> > res(n, vector<int>(n));

        int value = 1;
        int left = 0, top = 0;
        int right = n-1, down = n-1;

        while(left <= right && top <= down)
        {
            //going right
            for(int j = left; j <= right; j++)
                res[top][j] = value++;

            top++;
            //going down
            for(int i = top; i <= down; i++)
                res[i][right] = value++;

            right--;
            //going left
            for(int j = right; j >= left; j--)
                res[down][j] = value++;

            down--;
            //going up
            for(int i = down; i >= top; i--)
                res[i][left] = value++;

            left++;
        }
        return res;

        /*//Works but little slower due to double memory access for Fillflag check

        ///here we use -1 flag to stop and turn direction of writing values
        //it will be keepon writing if the coming index have -1 value
        vector<vector<int>> res(n, vector<int>(n, -1));

        int rem_to_be_filled = n*n;
        int curr_elem = 1;

        int it_i = 0, it_j = 0;
        while(rem_to_be_filled > 0)
        {
            //going right
            while(it_j < n && res[it_i][it_j] == -1)
            {
                cout<<curr_elem<<" ";
                res[it_i][it_j] = curr_elem;
                curr_elem++;
                rem_to_be_filled--;
                it_j++;
            }

            //going down
            it_j--; it_i++;
            while(it_i < n && res[it_i][it_j] == -1)
            {
                res[it_i][it_j] = curr_elem;
                curr_elem++;
                rem_to_be_filled--;
                it_i++;
            }

            //going left
            it_i--;it_j--;
            while(it_j >=0 && res[it_i][it_j] == -1)
            {
                res[it_i][it_j] = curr_elem;
                curr_elem++;
                rem_to_be_filled--;
                it_j--;
            }

            //going up
            it_j++;it_i--;
            while(it_i >= 0 && res[it_i][it_j] == -1)
            {
                res[it_i][it_j] = curr_elem;
                curr_elem++;
                rem_to_be_filled--;
                it_i--;
            }

            it_i++;it_j++;
        }

        return res; */
    }
