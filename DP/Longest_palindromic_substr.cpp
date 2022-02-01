/*
Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
*/
string longestPalindrome(string s) {

        if(s.size() == 1) return {s[0]};

        pair<int,int> pl_max = {1,0};/// {len,startPos}

        for(int i = 0 ; i < s.size()-1; i++)
        {
            pair<int,int> odd_pal  = getMaxPalindCenteredAt_l_r(s, i, i);
            pair<int,int> even_pal = getMaxPalindCenteredAt_l_r(s, i, i+1);

            pair<int,int> curr_max = (odd_pal.first > even_pal.first) ? odd_pal:even_pal ;

            if(curr_max.first > pl_max.first)
                pl_max = curr_max;

        }

        return s.substr(pl_max.second, pl_max.first);
    }

    pair<int,int> getMaxPalindCenteredAt_l_r(string& s, int l, int r)
    {

        while(l >=0 && r < s.length() && s[l] == s[r])
        {
            l--;
            r++;
        }

        int pl_start = l + 1;
        int pl_len   = r - l -1;

        return {pl_len, pl_start};
    }
