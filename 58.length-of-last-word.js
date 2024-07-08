/*
 * @lc app=leetcode id=58 lang=javascript
 *
 * [58] Length of Last Word
 */

// @lc code=start
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let ok = false;
    let ans= '';

    for (let i = s.length - 1; i >= 0; i--)
    {
        if (s[i] === ' ')	
        {
            if (ok)
            {
                break;
            }
            continue;
        }

        ok = true;
        ans += s[i];
    }
    ans = ans.split('').reverse().join('');
    return ans.length;

};
// @lc code=end

