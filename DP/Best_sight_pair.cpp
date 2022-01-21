/*
You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.



Example 1:

Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11


*/
int maxScoreSightseeingPair(vector<int>& values) {

        int max_score = values[0];

        //prev best index initilized as first index
        int prv_bst_idx = 0;

        //since prev_bst_idx will be the 'i' then we are finding the 'j'
        for (int j = 1; j < values.size(); j++)
        {
            int curr_score = values[prv_bst_idx] + values[j] + prv_bst_idx - j;//score formulae
            max_score = max (max_score,  curr_score);//updating max_score

            //updating prev_bst_idx
            if((values[prv_bst_idx] + prv_bst_idx ) <= (values[j] + j) )
                prv_bst_idx = j;

        }
        return max_score;
    }
