/*
 * @lc app=leetcode id=16 lang=csharp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
public class Solution
{
    public int ThreeSumClosest(int[] nums, int target)
    {
        Array.Sort(nums);
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.Length - 2; i++)
        {
            int l = i + 1, r = nums.Length - 1;
            while (l < r)
            {
                int now = nums[i] + nums[l] + nums[r];
                if (Math.Abs(target - now) <= Math.Abs(target - ans))
                {
                    ans = now;
                }
                if (now < target)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return ans;

    }
}
// @lc code=end

