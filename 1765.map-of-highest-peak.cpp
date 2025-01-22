/*
 * @lc app=leetcode id=1765 lang=cpp
 *
 * [1765] Map of Highest Peak
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {

        vector<vector<int>> ans(isWater.size(), vector<int>(isWater[0].size(), INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < isWater.size(); i++)
        {
            for (int j = 0; j < isWater[0].size(); j++)
            {
                if (isWater[i][j] == 1)
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if (nr >= 0 && nr < isWater.size() && nc >= 0 && nc < isWater[0].size() && ans[nr][nc] == INT_MAX)
                {
                    ans[nr][nc] = ans[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return ans;
    }
};
// @lc code=end
