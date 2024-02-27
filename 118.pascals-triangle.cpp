/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans(numRows);

        for (int i = 0; i < numRows; i++)
        {
            if (i == 0)
            {
                ans[i].push_back(1);
            }
            if (i == 1)
            {
                ans[i].push_back(1);
                ans[i].push_back(1);
            }

            if (i > 1)
            {
                ans[i].push_back(1);
                for (int j = 1; j < i; j++)
                {
                    ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
                ans[i].push_back(1);
            }
        }
        return ans;
    }
};
// @lc code=end
