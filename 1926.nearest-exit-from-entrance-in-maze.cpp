/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int x = entrance[0];
        int y = entrance[1];
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        int row = maze.size();
        int col = maze[0].size();
        int ans = INT_MAX;
        queue < pair < pair<int, int>, int >> q;
        q.push({{x, y}, 0});

        bool vis[row + 1][col + 1];
        memset(vis, false, sizeof vis);

        vis[x][y] = true;

    
        
        while(!q.empty())
        {
            pair<pair<int, int>, int> p = q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nx = p.first.first + dx[i];
                int ny = p.first.second + dy[i];
                int dist = p.second + 1;
                if(nx>=0 and ny>=0 and nx<row and ny<col and !vis[nx][ny] and maze[nx][ny] == '.')
                {
                    if(nx==0 or nx==row-1 or ny==0 or ny==col-1)
                    {
                        ans = min(ans, dist);
                    }
                    q.push({{nx, ny}, dist});
                    vis[nx][ny] = true;
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end

