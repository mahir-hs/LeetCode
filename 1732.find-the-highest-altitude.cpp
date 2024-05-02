/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int ans = 0;
        int last = 0;
        for (int i = 0;i<gain.size();i++)
        {
            last += gain[i];
            ans = max(ans, last);
        }
        return ans;
    }
};
// @lc code=end

