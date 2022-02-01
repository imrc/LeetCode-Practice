/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:




Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/
vector<vector<int>> generate(int numRows) {


        vector<vector<int>> res;

        res.push_back({1});

        for(int i = 1; i < numRows; i++)
        {
            vector<int> curr;
            for(int j = 0; j<=i; j++)
            {
                if(j == 0)
                    curr.push_back(1);//left most of any row is 1

                else if(j == i)
                    curr.push_back(1);//right most of any row is 1

                else
                    curr.push_back(res[i-1][j-1] + res[i-1][j] );

            }

            //pushing curr row to result
            res.push_back(curr);
        }

        return res;
    }
