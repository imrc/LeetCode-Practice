/*

Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

i - k <= r <= i + k,
j - k <= c <= j + k, and
(r, c) is a valid position in the matrix.


Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

*/

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        int m = mat.size();
        int n = mat[0].size();

      ///  ////Calculating prefixSumMatrix
        vector<vector<int>> pref_matx(m,vector<int>(n));

        //initializing (0,0)
        pref_matx[0][0] = mat[0][0];

        //filling 1st row
        for(int j = 1; j< n; j++)
            pref_matx[0][j] += mat[0][j] + pref_matx[0][j-1];

        //filling 1st column
        for(int i = 1; i< m; i++)
            pref_matx[i][0] += mat[i][0] + pref_matx[i-1][0];

        for(int i = 1; i < m; i ++)
            for(int j = 1; j < n; j++)
            {
                pref_matx[i][j] += mat[i][j] + pref_matx[i-1][j] + pref_matx[i][j-1] - pref_matx[i-1][j-1];
            }

    ////    ///// Calculating Block sum matrix from prefix matrix
        vector<vector<int>> res(m,vector<int>(n));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                //calculating top left of mat block
                int tl_i = 0, tl_j = 0;
                if(i-k > 0)
                    tl_i = i-k;
                if(j-k > 0)
                    tl_j = j-k;

                //calculating bottom right of mat block
                int br_i = m-1, br_j = n-1;
                if(i+k < m-1)
                    br_i = i+k;
                if(j+k < n-1)
                    br_j = j+k;

                res[i][j] = pref_matx[br_i][br_j]
                            +( (tl_i == 0 || tl_j == 0) ? 0 : pref_matx[tl_i-1][tl_j-1] ) //
                            -( (tl_i == 0) ? 0: pref_matx[tl_i-1][br_j] )
                            -( (tl_j == 0) ? 0: pref_matx[br_i][tl_j-1] );

            }

            return res;
    }
