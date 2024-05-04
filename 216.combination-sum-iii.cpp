/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;

    void go(int k, int n, int cur, vector<int> &values)
    {

        if (n < 0 or values.size() > k)
            return;
        if (k == values.size() and n == 0)
        {
            ans.push_back(values);
            return;
        }

        for (int i = cur; i < 10; i++)
        {
            values.push_back(i);
            go(k, n - i, i + 1, values);
            values.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> values;
        go(k, n, 1, values);
        return ans;
    }
};
// @lc code=end
