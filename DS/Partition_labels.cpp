/*
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.



Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
*/
vector<int> partitionLabels(string s) {

        ///hashMap with key = char, value = {start,end}
        unordered_map<char, pair<int,int> >  hash;

        for(int i = 0; i < s.size(); i++)
        {
            if(hash.count(s[i]) == 1)
            {///if already exist update 'end'
                hash[s[i]].second = i;
            }
            else
            {
                hash[s[i]] = {i, i}; //initiaize both 'start' and 'end' as i
            }
        }

         set<pair<int,int>> intervals; /// sort the intervals to accending order so as to merge them later
         ///adding all intervals to a vector
         for(auto elem: hash)
         {
             intervals.insert(elem.second);
         }

        ///merge intervals and find partition lens
       vector<int> non_overlp_intervels_len;

       int start = intervals.begin()->first;
       int end   = intervals.begin()->second;

        auto st = intervals.begin();
        advance(st, 1);

        for(auto it = st; it != intervals.end(); it++)
        {
            if(end >= it->first)
                end = max (end, it->second);

            else
            {
                int part_len = end - start + 1;
                non_overlp_intervels_len.push_back(part_len);
                start =  it->first;
                end   =  it->second;
            }

        }

        int part_len = end - start + 1; //last interval
        non_overlp_intervels_len.push_back(part_len);

        return non_overlp_intervels_len;


    }
