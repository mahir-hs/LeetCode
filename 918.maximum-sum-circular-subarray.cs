/*
 * @lc app=leetcode id=918 lang=csharp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
public class Solution
{
    public int MaxSubarraySumCircular(int[] nums)
    {
        int noC = go(nums);
        int ans = 0;
        for(int i = 0;i<nums.Length;i++)
        {
            ans += nums[i];
            nums[i] = -nums[i];
        }
        int c = ans+go(nums);
        if(c==0)
            return noC;
        return Math.Max(noC,c);
    }

    public int go(int[] nums)
    {
        int max = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            sum += nums[i];
            max = Math.Max(max, sum);
            if (sum < 0)
                sum = 0;
        }
        return max;
    }
}
// @lc code=end

