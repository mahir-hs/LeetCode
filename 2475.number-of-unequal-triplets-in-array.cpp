/*
 * @lc app=leetcode id=2475 lang=cpp
 *
 * [2475] Number of Unequal Triplets in Array
 */

// @lc code=start
class Solution
{
public:
    int unequalTriplets(vector<int> &nums)
    {

        unordered_map<int, int> m;
        for (int n : nums)
            ++m[n];
        int res = 0, left = 0, right = nums.size();
        for (auto [n, cnt] : m)
        {
            right -= cnt;
            res += left * cnt * right;
            left += cnt;

            // cout<<n<<" "<<cnt<<" "<<left<<" "<<right<<" "<<res<<endl;
        }
        return res;
    }
};
// @lc code=end
