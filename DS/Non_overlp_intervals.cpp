/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.



Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
*/

int eraseOverlapIntervals(vector<vector<int>>& intervals) {

       auto cmp_fn = [](const vector<int> &x, const vector<int> &y)
                        {return x[1]<y[1];}; //sorting based on end value alone
        sort(intervals.begin(), intervals.end(), cmp_fn);
        int len = intervals.size();

        /////
        int overlp_end_sofar = intervals[0][1];
        int overlp_cnt = 0;

        for(int i = 1; i < len; i++)
        {
            if(overlp_end_sofar > intervals[i][0])//overlapping
                overlp_cnt++;
            else
                overlp_end_sofar = intervals[i][1];
        }

        return overlp_cnt;

        /////
        /* ///Correct but O(n^2) soo time limit exceeded
        ///This is variation of LIS or Activity selection problem

        vector<int> dp(len);

        int max_non_overlap = 1;

        dp[0] = 1;

        for(int i = 1; i<len; i++)
        {
            dp[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(intervals[i][0] >= intervals[j][1])
                    dp[i] = max( dp[i], dp[j] + 1);
            }
             max_non_overlap = max (max_non_overlap, dp[i]);
            cout<<max_non_overlap<<" ";
        }

        return len - max_non_overlap;
    */
    }
