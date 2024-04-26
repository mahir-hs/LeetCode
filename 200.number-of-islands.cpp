/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution
{
public:
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    void dfs(vector<vector<char>> &grid, int i, int j)
    {

        if (grid[i][j] == '1')
        {
            grid[i][j] = '0';
            for (int k = 0; k < 4; k++)
            {
                int xx = i + x[k];
                int yy = j + y[k];
                if (xx >= 0 && xx < grid.size() && yy >= 0 && yy < grid[0].size())
                    dfs(grid, xx, yy);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {

        int row = grid.size();
        int col = grid[0].size();

        int island = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    island++;
                }
            }
        }
        return island;
    }
};
// @lc code=end
