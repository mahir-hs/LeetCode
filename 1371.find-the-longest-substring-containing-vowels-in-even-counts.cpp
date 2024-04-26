/*
 * @lc app=leetcode id=1371 lang=cpp
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 */

// @lc code=start
class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_set<char>vowel = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<int,int>m;
        m[0] = -1;
        int mask = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(vowel.count(s[i])){
                mask ^= (1 << (s[i] - 'a'));
            }
            if(m.count(mask)){
                ans = max(ans, i - m[mask]);
            }
            else{
                m[mask] = i;
            }
        }
        return ans;
    }
};
// @lc code=end

