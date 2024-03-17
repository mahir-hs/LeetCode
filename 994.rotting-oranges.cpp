/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        bool vis[m+1][n+1];
        memset(vis, false, sizeof(vis));
        while (!q.empty()) {
            pair<pair<int,int>, int> p = q.front();
            vis[p.first.first][p.first.second] = true;
            ans = max(ans, p.second);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = p.first.first + dx[i];
                int y = p.first.second + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && !vis[x][y]) {
                    vis[x][y] = true;
                    grid[x][y] = 2;
                    q.push({{x, y}, p.second + 1});
                }
             }
             
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
       return ans;
    }
};
// @lc code=end

