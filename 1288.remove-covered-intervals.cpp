/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 */

// @lc code=start
class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0]; });

        int res = 0;
        int left = intervals[0][0];
        int right = intervals[0][1];
        res++;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (left == intervals[i][0])
            {
                continue;
            }
            else
            {
                if (right >= intervals[i][1])
                {
                    continue;
                }
                else
                {
                    res++;
                    left = intervals[i][0];
                    right = intervals[i][1];
                }
            }
        }
        return res;
    }
};
// @lc code=end
