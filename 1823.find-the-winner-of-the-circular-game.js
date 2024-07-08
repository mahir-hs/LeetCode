/*
 * @lc app=leetcode id=1823 lang=javascript
 *
 * [1823] Find the Winner of the Circular Game
 */

// @lc code=start
/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findTheWinner = function(n, k) {
    let cur = 1;
    for(let i = 2; i <= n; i++){
        cur = (cur + k - 1) % i + 1;
    }
    return cur
};
// @lc code=end

