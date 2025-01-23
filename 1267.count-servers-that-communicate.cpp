/*
 * @lc app=leetcode id=1267 lang=cpp
 *
 * [1267] Count Servers that Communicate
 */

// @lc code=start
class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int row[250] = {0};
        int col[250] = {0};
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
