/*

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
*/


void rotate(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        ///clockwiseRotated image = rotate the matrix and then reverse on the vertical axis

        //rotating image along diagonal
        for(int i = 0; i < m; i++)
            for(int j = i + 1; j < n; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }

        //reverse along the centre vertical
        for(int i = 0; i < m; i++)
        {
            int low = 0, high = n-1;
            while(low < high)
            {
                int tmp = matrix[i][low];
                matrix[i][low] = matrix[i][high];
                matrix[i][high] = tmp;

                low++;high--;
            }

        }

        return ;

    }
