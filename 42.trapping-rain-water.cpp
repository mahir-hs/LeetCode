/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {

        stack<int> st;

        int ans = 0;

        for (int i = 0; i < height.size(); i++)
        {

            while (!st.empty() && height[st.top()] < height[i])
            {
                int cur = st.top();

                st.pop();

                if (st.empty())
                    break;

                int left = st.top();
                int right = i;

                int h = min(height[left], height[right]) - height[cur];

                ans += (right - left - 1) * h;
            }

            st.push(i);

        }

        return ans;
    }
};
// @lc code=end
