/*
 * @lc app=leetcode id=1791 lang=csharp
 *
 * [1791] Find Center of Star Graph
 */

// @lc code=start
public class Solution
{
    public int FindCenter(int[][] edges)
    {
        int[] arr = new int[100005];
        foreach (int[] edge in edges)
        {
            arr[edge[0]]++;
            arr[edge[1]]++;
            if (arr[edge[0]] > 1)
            {
                return edge[0];
            }
            if (arr[edge[1]] > 1)
            {
                return edge[1];
            }
        }
        return 0;
    }
}
// @lc code=end

