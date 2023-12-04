/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        int ans = -1e3;
        int l = 1, r = 1;
        int n = nums.size();
        for (int i = 0, j = n - 1; i < n; i++, j--)
        {
            l *= nums[i];
            ans = max(ans, l);
            if(l==0)
                l = 1;

            r *= nums[j];
            ans = max(ans, r);
            if(r==0)
                r = 1;
        }
        return ans;
    }
};
// @lc code=end
