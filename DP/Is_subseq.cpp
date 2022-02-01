 bool isSubsequence(string s, string t)
    {

        //while traversing the main string we compare the chars of subSeq from 1st index if match we moves the index when all the chars subSeq are matched on or before the main string traversal completes then we can say the subSeq is there in main string
        int subS_pos = 0;
        for(char& elem: t)
        {
            if(subS_pos >= s.size())
                return true;
            else if (s[subS_pos] == elem)
                subS_pos++;

        }

        if(subS_pos >= s.size())
            return true;
        else
            return false;
    }
