/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 */

// @lc code=start
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = A.size();
        if (row == 0)
            return 0;
        int col = A[0].size();

       
        for (int i = 0; i < row; i++)
            if (!A[i][0])
                for (int j = 0; j < col; j++)
                    A[i][j] = 1 - A[i][j];

        
        int ans = 0;
        for (int j = 0; j < col; j++)
        {
            int sum = 0;
            for (int i = 0; i < row; i++)
                if (A[i][j])
                    sum++;
            ans += max(sum, row - sum) * pow(2, col - 1 - j);
        }

        return ans;
    }
};
// @lc code=end

