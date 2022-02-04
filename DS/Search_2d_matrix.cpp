/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.


Example 1:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        ////Logic:->
        ///1. We start  from top-right corner
        /// if target is > value --- target cant be in that row
        //// if target is < value -- target cant be in that column
        /// soo we decrement colmn-index or increment row index accordinglyy
        ///complexity --> O(m+n)

        int i  = 0, j = n-1;

        while(i < m && j >= 0)
        {
            if (target == matrix[i][j])
                return true;

            else if (target > matrix[i][j])
                i++;

            else ///target < matrix[i][j]
                j--;

        }

        return false;


    }
