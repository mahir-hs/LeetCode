/*
 * @lc app=leetcode id=2895 lang=cpp
 *
 * [2895] Minimum Processing Time
 */

// @lc code=start
class Solution
{
public:
    int minProcessingTime(vector<int> &processorTime, vector<int> &tasks)
    {
        sort(processorTime.rbegin(), processorTime.rend());
        sort(tasks.begin(), tasks.end());
        vector<int> ans;
        int j = 0;

        for (int i = 3; i < tasks.size(); i += 4)
        {
            ans.push_back(tasks[i] + processorTime[j++]);
        }
        return *max_element(ans.begin(), ans.end());
    }
};
// @lc code=end
