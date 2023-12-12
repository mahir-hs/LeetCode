/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        int sz = (nums.size() + 1) / 2;

        int cnt = 0;
        int last = nums[0];
        int val = 0, mx = 0;
        for (auto k : nums)
        {
            if (last == k)
            {
                cnt++;
                if (cnt > mx)
                {
                    mx = cnt;
                    val = k;
                }
            }
            else
            {
                if (cnt > mx)
                {
                    mx = cnt;
                    val = k;
                }
                cnt = 1;
                last = k;
            }
        }
        
        if (cnt > mx)
        {
            mx = cnt;
            val = nums.back();
        }
        return val;
    }
};
// @lc code=end
