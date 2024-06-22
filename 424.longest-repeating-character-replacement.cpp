/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int ans = 0;
        int left = 0;
        int right = 0;
        int maxf = 0;
        while(right < s.size()) {
            m[s[right]]++;
            maxf = max(maxf, m[s[right]]);
            if((right - left + 1) - maxf > k) {
                m[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
// @lc code=end

