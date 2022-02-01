/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.



Example 1:


Input: n = 3
Output: 5

*/

int numTrees(int n) {

        //here the no. of unique BST's having nodes 1->n will be nth catalan number;

        return catalan(n);
    }

    int catalan(int n)
    {
        //nth catalan num = binomial coeficciant 2nCn divided by n+1
        long int c = binCo(2*n, n);

        return c/(n+1);
    }

    long int binCo(int n, int k)
    {
        if(k > n-k)
            k = n-k; //bcz nCk = nC(n-k)

        long int res = 1;

        for(int i = 0; i<k ; i++)
        {
            //due to relation nCk = (n*n-1*n-2.....n-k+1) / (k*k-1*k-2*.....1)
            res *= (n-i);
            res /= (i+1);
        }

        return res;

    }
