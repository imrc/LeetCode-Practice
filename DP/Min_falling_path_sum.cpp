/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).



Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
*/


int minFallingPathSum(vector<vector<int>>& matrix) {

        //very similar to triangle question

        int numRows = matrix.size();

        //We do bottom up manner // considering DP array as input array itself // we start from 2nd last , since last row already contains min_sum_falling_ending at that index

        for(int i = numRows - 2; i >= 0; i--)
        {
                            //n * n matrix
            for(int j = 0; j < numRows; j++)
            {
                if(j == 0)//this index has no diagonaly left elem below
                    matrix[i][j] = matrix[i][j] + min (matrix[i+1][j], matrix[i+1][j+1]);

                else if (j == numRows-1)//this index has no diagonaly right elem below
                    matrix[i][j] = matrix[i][j] + min (matrix[i+1][j-1], matrix[i+1][j]);

                else //min of elem just below, elem diaginally left, elem diaginally right
                    matrix[i][j] = matrix[i][j] + min (matrix[i+1][j], min (matrix[i+1][j-1], matrix[i+1][j+1]));
            }


        }

        //Now Top row cotains min_falling_path_sum starting at each index// result will be min of ALL
        return *min_element (matrix[0].begin(), matrix[0].end());

    }
