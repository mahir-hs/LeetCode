/*
 * @lc app=leetcode id=2948 lang=cpp
 *
 * [2948] Make Lexicographically Smallest Array by Swapping Elements
 */

// @lc code=start
class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {

        vector<pair<int, int>> vp;

        for (int i = 0; i < nums.size(); i++)
        {
            vp.push_back({nums[i], i});
        }

        sort(vp.begin(), vp.end());

        vector<vector<pair<int, int>>> v;
        v.push_back({vp[0]});

        for (int i = 1; i < vp.size(); i++)
        {
            if (vp[i].first - vp[i - 1].first <= limit)
            {
                v.back().push_back(vp[i]);
            }
            else
            {
                v.push_back({vp[i]});
            }
        }

        for (auto k : v)
        {
            vector<int> temp;

            for (auto [x, y] : k)
            {
                temp.push_back(y);
            }
            sort(temp.begin(), temp.end());

            for (int i = 0; i < temp.size(); i++)
            {
                nums[temp[i]] = k[i].first;
            }
        }
        return nums;
    }
};
// @lc code=end
