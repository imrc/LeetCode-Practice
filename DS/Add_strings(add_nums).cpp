/*
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.



Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
*/
string addStrings(string num1, string num2) {


        int carry = 0;
        string res = "";

        int i = num1.size()-1;
        int j = num2.size()-1;

        while(i >= 0 || j >= 0)
        {
            int digit1 = 0, digit2 = 0;

            if( i>= 0)
                digit1 = int(num1[i]-'0');

            if( j>= 0)
                digit2 = int(num2[j]-'0');

            int sum = digit1 + digit2 + carry;
            int q = sum%10;

            res = to_string(q) + res;

            carry = sum/10;

            i--;
            j--;
        }

        if(carry != 0)
            res = to_string(carry) + res;

        return res;
    }
