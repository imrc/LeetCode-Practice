/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return true if n is an ugly number.



Example 1:

Input: n = 6
Output: true
Explanation: 6 = 2 × 3
*/
bool isUgly(int num) {

        if(num <= 0)
            return false;// ugly num is a +ve number

        while(num%2 == 0)
            num = num/2;

        while(num%3 == 0)
            num = num/3;

        while(num%5 == 0)
            num = num/5;

        ///After all these the number will got rid of all 2,3,5 factors
        ///soo if ugly num then num will have become 1;

        if(num == 1)
            return true;
        else
            return false;



        /*Not fast soln//works

        //https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/


        if(num <= 0)////ugly num is a +ve number
            return false;

        if(num < 7)
            return true;

        while(num%2 == 0)
        {
            num = num/2;
        }

        for(int i = 3; i <= sqrt(num); i = i + 2)
        {


            while(num%i == 0)
            {
                if(i > 5)
                    return false;

                num = num/i;
            }
        }

    ///if n> 5 then it is a prime number so not ugly number
    if(num > 5)
        return false;
    else
        return true;
        */


    }
