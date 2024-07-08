/*
 * @lc app=leetcode id=14 lang=javascript
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {

    let ans= '';
    for (let i = 0; i < strs[0].length; i++) {
        let now = strs[0][i];

        for (let j = 1; j < strs.length; j++) {
            if (strs[j][i] !== now) {
                return ans;
            }
        }

        ans += now;

    }

    return ans;
    
};
// @lc code=end

