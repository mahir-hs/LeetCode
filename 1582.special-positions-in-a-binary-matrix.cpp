/*
 * @lc app=leetcode id=1582 lang=cpp
 *
 * [1582] Special Positions in a Binary Matrix
 */

// @lc code=start
class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {

        map<int, int> row, col;
        int ans = 0;

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                col[j] += mat[i][j];
                row[i] += mat[i][j];
            }
            // cout << row[i] << endl;
        }
        // for (int i = 0; i < mat[0].size(); i++)
        // {
        //     cout << col[i] << endl;
        // }

        for (int i = 0; i < mat.size(); i++)
        {
            if (row[i] > 1)
                continue;
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 1 and col[j] == 1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
// [ [ 0, 0 ], [ 0, 0 ], [ 1, 0 ] ]