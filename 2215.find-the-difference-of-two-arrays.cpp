/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {

        unordered_map<int, int> a, b;
        vector<vector<int>> ans;
        for (auto k : nums1)
            a[k]++;
        for (auto k : nums2)
            b[k]++;

        vector<int> temp;
        for (auto k : nums1)
        {
            if (b[k] == 0)
            {
                temp.push_back(k);
                b[k] = 1;
            }
        }
        ans.push_back(temp);
        temp.clear();
        for (auto k : nums2)
        {
            if (a[k] == 0)
            {
                temp.push_back(k);
                a[k] = 1;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
// @lc code=end
