/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;

        for (auto k : nums)
        {
            if (i == 0 or i == 1 or nums[i - 2] != k)
            {
                nums[i] = k;
                i++;
            }
        }
        return i;
    }
};
// @lc code=end
