/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;
        vector<int> heights(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
        
    }

    int largestRectangleArea(vector<int>& heights) {

        int ans = 0;
        stack<int> st;

        for (int i = 0; i <= heights.size(); i++) {
            while (!st.empty() && (i == heights.size() || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;

                ans = max(ans, height * width);
            }

            st.push(i);
        }

        return ans;

    }
};
// @lc code=end

