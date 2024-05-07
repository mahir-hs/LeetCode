/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {

        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {

            while (st.empty() == false and temperatures[i] >= temperatures[st.top()])
                st.pop();

            if (st.empty())
            {
                ans[i] = 0;
            }
            else
            {
                ans[i] = st.top() - i;
            }

            st.push(i);
        }
        return ans;
    }
};
// @lc code=end
