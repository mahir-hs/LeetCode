/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int ticket = 0;
        if (nums.size() == 1)
            return true;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                if (nums[i] == 0)
                    return false;
                ticket = nums[i];
                continue;
            }
            if (ticket == 0)
                return false;
            ticket--;
            ticket = max(ticket, nums[i]);
        }
        return true;
    }
};
// @lc code=end
