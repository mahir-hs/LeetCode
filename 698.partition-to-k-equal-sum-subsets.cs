/*
 * @lc app=leetcode id=698 lang=csharp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
public class Solution {
    public bool CanPartitionKSubsets(int[] nums, int k) {
        Array.Sort(nums);
        int sum = 0;
        for (int i = 0; i < nums.Length; i++)
            sum += nums[i];
        if (sum % k != 0)
            return false;
        int target = sum / k;
        bool[] visited = new bool[nums.Length];
        return dfs(nums, visited, 0, target, 0, k);     

        bool dfs(int[] nums, bool[] visited, int index, int target, int sum, int k)
        {
            if (k == 0)
                return true;
            if (sum == target)
                return dfs(nums, visited, 0, target, 0, k - 1);
            for (int i = index; i < nums.Length; i++)
            {
                if (visited[i] || sum + nums[i] > target)
                    continue;
                visited[i] = true;
                if (dfs(nums, visited, i + 1, target, sum + nums[i], k))
                    return true;
                visited[i] = false;
            }
            return false;
        }
    }
}
// @lc code=end

