/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.



Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/

vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end()); //sorting intervals

        int start = intervals[0][0];

        int max_end_so_far = intervals[0][1];

        int len = intervals.size();

        for(int i = 1; i < len; i++)
        {

            if(max_end_so_far >= intervals[i][0]) ///Overlap detected
                max_end_so_far = max(max_end_so_far, intervals[i][1]);

            else
            {///push to result when no overlap with max_end_so_far and curr_start

                res.push_back({start,max_end_so_far});

                start = intervals[i][0];

                max_end_so_far = intervals[i][1];///resets max_end_so_far as we detected no overlap
            }

        }

        res.push_back({start,  max_end_so_far});

        return res;

    }
