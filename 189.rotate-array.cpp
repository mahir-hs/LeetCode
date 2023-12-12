/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

        int sz = nums.size();
        int r = __gcd(sz, k);

        for (int i = 0; i < r;i++)
        {
            for (int j = (i + k) % sz; i != j;j = (j+k)%sz)
            {
                cout << i << " " << j << endl;
                swap(nums[i], nums[j]);
            }
        }
    }
};
// @lc code=end
