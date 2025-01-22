/*
 * @lc app=leetcode id=1605 lang=cpp
 *
 * [1605] Find Valid Matrix Given Row and Column Sums
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {

        vector<vector<int>> ans;
        ans.resize(rowSum.size(), vector<int>(colSum.size(), 0));

        for (int i = 0; i < rowSum.size(); i++)
        {
            for (int j = 0; j < colSum.size(); j++)
            {
                ans[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
            }
        }

        return ans;
    }
};
// @lc code=end
