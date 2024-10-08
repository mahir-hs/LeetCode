/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size(), max_area = 0;
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                max_area = max(max_area, h * w);
            }
            s.push(i);
        }

        while (!s.empty())
        {
            int h = heights[s.top()];
            s.pop();
            int w = s.empty() ? n : n - s.top() - 1;
            max_area = max(max_area, h * w);
        }
        return max_area;
    }
};
// @lc code=end
