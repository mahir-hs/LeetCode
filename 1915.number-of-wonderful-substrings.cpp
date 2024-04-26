/*
 * @lc app=leetcode id=1915 lang=cpp
 *
 * [1915] Number of Wonderful Substrings
 */

// @lc code=start
class Solution {
public:
    long long wonderfulSubstrings(string word) {

        unordered_map<int, int> m;
        m[0] = 1;

        long long ans = 0;
        int mask = 0;

        for (int i = 0; i < word.size(); i++) {

            mask ^= (1 << (word[i] - 'a'));
            ans += m[mask];
            for (int j = 0; j < 10; j++) {
                ans += m[mask ^ (1 << j)];
            }
            m[mask]++;
        }
        return ans;
    }
};
// @lc code=end

