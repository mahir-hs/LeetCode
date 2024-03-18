/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

// @lc code=start
class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {

        vector<int> adj[n];
        for (auto k : connections)
        {
            adj[k[0]].push_back(k[1]);
            adj[k[1]].push_back(-k[0]);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        function<void(int, vector<int>[], vector<bool> &, int &)> dfs = [&](int node, vector<int> adj[], vector<bool> &vis, int &ans)
        {
            vis[node] = true;
            for (auto k : adj[node])
            {
                if (!vis[abs(k)])
                {
                    if (k > 0)
                    {
                        ans++;
                    }
                    dfs(abs(k), adj, vis, ans);
                }
            }
        };
        dfs(0, adj, vis, ans);
        return ans;
    }
};
// @lc code=end
