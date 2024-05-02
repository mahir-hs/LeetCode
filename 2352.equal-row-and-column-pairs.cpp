/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 */

// @lc code=start
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        map<vector<int>, int> row,col;

        for (int i = 0; i < grid.size(); i++)
        {
            row[grid[i]]++;
        }

        for (int i = 0; i < grid[0].size(); i++)
        {
            vector<int> temp;
            for (int j = 0; j < grid.size(); j++)
            {
                temp.push_back(grid[j][i]);
            }
            col[temp]++;
        }
        int ans = 0;

        for (auto i : row)
        {
                ans += i.second*col[i.first];
        }
        return ans;
        
    }
};
// @lc code=end

