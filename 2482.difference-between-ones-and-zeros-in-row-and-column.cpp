/*
 * @lc app=leetcode id=2482 lang=cpp
 *
 * [2482] Difference Between Ones and Zeros in Row and Column
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {

        unordered_map<int, int> row, col;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }

        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> ans(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int now = row[i] + col[j] - (r - row[i]) - (c - col[j]);
                ans[i][j] = now;
            }
        }

        return ans;
    }
};
// @lc code=end
