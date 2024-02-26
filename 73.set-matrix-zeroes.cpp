/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool x = false;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
                x = true;
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                matrix[i][j] = (matrix[i][0] == 0 || matrix[0][j] == 0) ? 0 : matrix[i][j];
            }
        }
        for (int j = 1; j < matrix[0].size(); j++)
        {
            matrix[0][j] = (matrix[0][0] == 0) ? 0 : matrix[0][j];
        }
        if (x)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }
        return;
    }
};
// @lc code=end
