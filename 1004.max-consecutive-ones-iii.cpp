/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {

        int cnt = 0, ans = 0, zero = 0;
        int i = 0, j = 0;

        while (i < nums.size())
        {
            if (nums[i] == 1)
            {
                cnt++;
            }
            else
            {
                if (zero < k)
                {
                    zero++;
                    cnt++;
                }
                else
                {
                    while (j <= i)
                    {
                        if (nums[j] == 0)
                        {
                            j++;
                            break;
                        }
                        cnt--;
                        j++;
                    }
                }
            }
            i++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
// @lc code=end
