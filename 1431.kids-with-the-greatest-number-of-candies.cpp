/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> ans;
        int x = *max_element(candies.begin(), candies.end());
        for (auto k : candies)
            ans.push_back((k + extraCandies >= x) ? true : false);
        return ans;
    }
};
// @lc code=end
