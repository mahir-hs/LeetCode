/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    void go(vector<int> &nums, int i)
    {
        if (i == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            go(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        go(nums, 0);
        return ans;
    }
};
// @lc code=end
