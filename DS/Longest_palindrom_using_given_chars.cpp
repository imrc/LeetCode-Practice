/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.



Example 1:

Input: s = "abccccdd"
Output: 7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/
 int longestPalindrome(string s) {

        unordered_map<char, int > hash;

        for(char ch :s)
        {
            hash[ch]++;      ///counting Letters and Adding to hashMap
        }

        bool odd_cnt = false;

        int pal_len = 0;
        for(auto lett: hash)
        {
            if(lett.second%2 != 0)
                odd_cnt = true;      ///setting flag when odd cnt --> if odd count , we can add one letter in center (but max one letter)

            pal_len += lett.second/2;
        }


        return (pal_len*2 + (odd_cnt? 1 :0) );

    }
