/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int sz = gas.size();

        int sum = 0;
        int now = 0;
        int idx = 0;
        for (int i = 0; i < sz; i++)
        {
            sum += gas[i] - cost[i];
            now += gas[i] - cost[i];
            if (now < 0)
            {
                idx = i+1;
                now = 0;
            }
        }

        return sum >= 0 ? idx : -1;
    }
};
// @lc code=end

// 1 - 3 2 - 4 3 - 5 4 - 1 5 - 2, 1 - 3 2 - 4 3 - 5 4 - 1