/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:




Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
*/
vector<int> getRow(int rowIndex) {

        //0 intexed 'i'th row contains (i+1)nums
        vector<int> kthRow(rowIndex + 1);///it will be initialized as '0's to handle last index of each row { 0 + 1 = 1}

        kthRow[0] = 1;//intialization

        for(int i = 1; i<=rowIndex; i++)
        {

            for(int j = i; j > 0; j--)//start updating from last because prev_index of last row is needed for curr index updation (*curr_index also)
            {
                //NewValue at this index for currRow = PrevRowValue at this index + PrevRowValue at prev index
                kthRow[j] = kthRow[j] + kthRow[j-1];
            }

        }

        return kthRow;

    }
