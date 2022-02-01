/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.



Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
*/

int numDecodings(string s)
    {
        // empty string or leading zero means no way
        if(s.size() == 0 || s[0] == '0')
            return 0;

        int len = s.size();
        vector<int> dp(len+1);

        dp[0] = dp[1] = 1;

        //'1' indexing -- starting from 2nd index of string
        for(int i = 2; i <=len; i++)
        {   //Here dp[i-1] , dp[i-2]  contains ways of the last and the last of the last

            if(s[i-2] == '1' || s[i-2] == '2' && s[i-1] <= '6')
            {
                if(s[i-1] != '0')
                    dp[i] = dp[i-1] + dp[i-2] ;

                else// zero voids ways of the last because zero cannot be used separately
                    dp[i] = 0 + dp[i-2] ;

            }
            else
            {   // one-digit letter, no new way added
                if(s[i-1] != '0')
                        {
                            dp[i] = dp[i-1];
                        }
                else// zero voids ways of the last because zero cannot be used separately
                        {
                             dp[i] = 0;
                             dp[i-1] = 0;
                        }
            }

         }
        return dp[len];
    }
