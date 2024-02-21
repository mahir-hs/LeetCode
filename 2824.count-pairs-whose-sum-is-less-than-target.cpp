/*
 * @lc app=leetcode id=2824 lang=cpp
 *
 * [2824] Count Pairs Whose Sum is Less than Target
 */

// @lc code=start

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {

        int ans = 0;
        ordered_multiset<int> m;
        m.insert(nums[0]);
        // cout << 0 << endl;
        for (int i = 1; i < nums.size(); i++)
        {
            int now = target - nums[i];
            ans += m.order_of_key(now);
            // cout<<now<<" " << m.order_of_key(now) << endl;
            
            m.insert(nums[i]);
        }
        return ans;
    }
};
// @lc code=end
