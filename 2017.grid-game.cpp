/*
 * @lc app=leetcode id=2017 lang=cpp
 *
 * [2017] Grid Game
 */

// @lc code=start
class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        int c = grid[0].size();
        long long up[c + 1], down[c + 1];
        memset(up, 0, sizeof up);
        memset(down, 0, sizeof down);

        for (int i = c - 1; i >= 0; i--)
        {
            up[i] = up[i + 1] + grid[0][i];
            down[i] = down[i + 1] + grid[1][i];
        }

        vector<pair<long long, int>> vp;
        long long d = 0;
        for (int i = 0; i < c; i++)
        {
            d += grid[1][i];
            if (i == 0)
            {
                vp.push_back({up[i + 1], i});
                continue;
            }
            long long ans = max(d - grid[1][i], up[i + 1]);
            vp.push_back({ans, i});
        }

        sort(vp.begin(), vp.end());
        return vp[0].first;
    }
};
// @lc code=end
//[[20,3,20,17,2,12,15,17,4,15],[20,10,13,14,15,5,2,3,14,3]]