/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.



Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
*/


int nthUglyNumber(int n) {
       ///Concept uglynnumber will be powers of 2^n * 3^m * 5^k
        //soo to get nth ugly number we want to get these numbers in sorted order

        if(n <= 0)
            return false;

        //this arr stores (i+1)th ugly number
        vector<int> ugly_num(n);

        ugly_num[0] = 1;// because 1st ugly num is 1;

        int p1 = 0;  ///power of 2
        int p2 = 0;  ///power of 3
        int p3 = 0; //power of 5

        for(int i = 1; i < n; i++)//'0'indexing follwed
        {
            //(i+1)th ugly number {0 indexing follwd}
            ugly_num[i] = min (ugly_num[p1]*2, min (ugly_num[p2]*3, ugly_num[p3]*5 ));

            if(ugly_num[i] == ugly_num[p1]*2)
                p1++;

            /*else*/ if(ugly_num[i] == ugly_num[p2]*3) ///if only not 'else if'
                p2++;

            /*else*/ if(ugly_num[i] == ugly_num[p3]*5)///ugly_num[i] == ugly_num[p3]*5
                p3++;


        }
        //'nth'ugly num
        return ugly_num[n-1];

    }
