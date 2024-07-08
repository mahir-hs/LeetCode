/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for (int i = 0; i < nums1.size(); i++)
        {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        vector<vector<int>> ans;
        while (k-- && !pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            ans.push_back({nums1[it.second.first], nums2[it.second.second]});
            if (it.second.second + 1 < nums2.size())
            {
                pq.push({nums1[it.second.first] + nums2[it.second.second + 1], {it.second.first, it.second.second + 1}});
            }
        }
        return ans;
    }
};
// @lc code=end
