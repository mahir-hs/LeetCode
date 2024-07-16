/*
 * @lc app=leetcode id=219 lang=csharp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
public class Solution {
    public bool ContainsNearbyDuplicate(int[] nums, int k) {
        Dictionary<int, int> dict = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++)
        {
            if(dict.ContainsKey(nums[i]) && i - dict[nums[i]] <= k)
            {
                return true;
            }
            dict[nums[i]] = i;
        }

        return false;
    }
}
// @lc code=end

