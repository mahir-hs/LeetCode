/*
 * @lc app=leetcode id=1992 lang=cpp
 *
 * [1992] Find All Groups of Farmland
 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<vector<int>> &land, int i, int j, int &x, int &y)
    {
        if (i < 0 || j < 0 || i >= land.size() || j >= land[0].size() || land[i][j] == 0)
            return;

        land[i][j] = 0;
        x = max(x, i);
        y = max(y, j);

        dfs(land, i + 1, j, x, y);
        dfs(land, i - 1, j, x, y);
        dfs(land, i, j + 1, x, y);
        dfs(land, i, j - 1, x, y);
    }

    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {

        int row = land.size();
        int col = land[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (land[i][j] == 1)
                {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    int x = i, y = j;
                    dfs(land, i, j, x, y);
                    temp.push_back(x);
                    temp.push_back(y);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
