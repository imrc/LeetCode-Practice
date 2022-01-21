
/*

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.



Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
*/


/*   ///time_limit exceeded soln
    bool wBreak (string& s, unordered_set<string>& wordHash, int start)
    {

        if(start == s.size())
            return true;

        for(int i = 1; i <=  s.size()-start ; i++)
        {

            //searching substr i hash
           if( (wordHash.count (s.substr(start,i)) == true ) && wBreak(s, wordHash, start + i) )
               return true;


        }


        return false;

    }*/

   /* bool static bigger_s(const string& s1, const string& s2)
    {
        return (s1.size() > s2.size());
    }
    */

    //dp soln
    bool wordBreak(string s, vector<string>& wordDict) {


        unordered_set<string> wordHash(wordDict.begin(), wordDict.end());

        int s_len = s.size();

        //this dp array indicates if the string is breakable from 1st index to this pos
        vector <bool> breakable(s_len+1, false);

        //follows '1'indexing // if string is empty it is breakable
        breakable[0] = true;

        //'1' indexing followed
        for (int i = 1; i<= s_len; i++)
        {
            //checks if the string is breakable from the 1st index to 'i'th index OR from any already breakable index
            for(int j = 0; j<i; j++)
            {
            /*checks if th substr after a breakable index is there in dic - if there the whole str upto 'i' is breakble  //here substr starts at j because '1' indexing*/
                if((breakable[j] == true ) && (wordHash.count(s.substr(j,i-j)) == true) )
                {
                    breakable[i] = true;
                    break;
                }

            }

        }

        ///returns if the string is breakable upto last index
        return breakable[s_len];

    }
