/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.



Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
*/

 bool wordPattern(string pattern, string s) {

        int len = pattern.length();

        unordered_map<char,string> hash; /// to map words in s with  the chars in pattern
        unordered_set<string> word_tr;  ///to store already mapped words

        int s_pos = 0;
        for(int i = 0; i < len; i++)
        {

            int start = s_pos;
            while(s_pos < s.size() && s[s_pos] != ' ')
                s_pos++;

            if(start == s_pos)///words over but pattern doesnt
                return false;

            string currWord = s.substr(start, s_pos-start);

            cout<<currWord<<" ";

            if(hash.count(pattern[i]) == 1)
            {
                if(currWord != hash[pattern[i]])
                    return false;///pattern mismatch
            }
            else
            {
                if(word_tr.count(currWord) != 1) ///check if this word already mapped to any char
                    word_tr.insert(currWord);
                else
                    return false;////pattern mismatch since this word already mapped to another char before

                hash[pattern[i]] = currWord;
            }

            s_pos++;//move to next char right after space
        }

        if(s_pos == s.size() + 1)///checks if the string s is traversed to the end
            return true;
        else
            return false;


    }
