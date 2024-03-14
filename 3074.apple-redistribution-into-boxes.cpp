/*
 * @lc app=leetcode id=3074 lang=cpp
 *
 * [3074] Apple Redistribution into Boxes
 */

// @lc code=start
class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {

        sort(apple.rbegin(), apple.rend());
        sort(capacity.rbegin(), capacity.rend());
        int ans = 0;
        int left = 0;
        int i = 0;
        for (auto k : apple)
        {
            int now = left;

            while (now < k)
            {
                ans++;
                now += capacity[i++];
            }

            left = now - k;
        }
        return ans;
    }
};
// @lc code=end

