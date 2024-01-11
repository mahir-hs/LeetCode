/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {

        int ans = 0;
        int sz = nums.size();
        int cnt = 0;
        if (sz == 1)
            return 0;
        int last = 0, start = 0;
        while (last < sz - 1)
        {
            ans++;
            cnt = last + 1;
            for (int i = start; i <= last; i++)
            {
                if (i + nums[i] >= sz - 1)
                    return ans;
                cnt = max(cnt, i + nums[i]);
            }

            start = last + 1;
            last = cnt;
        }
        return ans;
    }
};
// @lc code=end
