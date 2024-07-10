/*
 * @lc app=leetcode id=1598 lang=javascript
 *
 * [1598] Crawler Log Folder
 */

// @lc code=start
/**
 * @param {string[]} logs
 * @return {number}
 */
var minOperations = function(logs) {
    let stack = [];

    for (let i = 0; i < logs.length; i++) {
        if (logs[i] === "../") {
            if (stack.length > 0) {
                stack.pop();
            }
        } else if (logs[i] !== "./") {
            stack.push(logs[i]);
        }
    }

    return stack.length;
};
// @lc code=end

