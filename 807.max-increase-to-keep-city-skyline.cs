/*
 * @lc app=leetcode id=807 lang=csharp
 *
 * [807] Max Increase to Keep City Skyline
 */

// @lc code=start
public class Solution {
    public int MaxIncreaseKeepingSkyline(int[][] grid) {
        
        int[] row = new int[grid.Length];
        int[] col = new int[grid[0].Length];
        for (int i = 0; i < grid.Length; i++)
        {
            for (int j = 0; j < grid[0].Length; j++)
            {
                row[i] = Math.Max(row[i], grid[i][j]);
                col[j] = Math.Max(col[j], grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < grid.Length; i++)
        {
            for (int j = 0; j < grid[0].Length; j++)
            {
                ans += Math.Min(row[i], col[j]) - grid[i][j];
            }
        }
        return ans;
    }
}
// @lc code=end

