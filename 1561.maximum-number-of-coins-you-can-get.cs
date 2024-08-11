/*
 * @lc app=leetcode id=1561 lang=csharp
 *
 * [1561] Maximum Number of Coins You Can Get
 */

// @lc code=start
public class Solution {
    public int MaxCoins(int[] piles) {
        Array.Sort(piles);
        int ans = 0;
        int i = 0;
        int j = piles.Length - 2;
        while(i < j){
            ans += piles[j];
            i++;
            j -= 2;
        }
        return ans;
    }
}
// @lc code=end

