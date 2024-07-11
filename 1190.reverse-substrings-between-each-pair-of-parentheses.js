/*
 * @lc app=leetcode id=1190 lang=javascript
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */

// @lc code=start
/**
 * @param {string} s
 * @return {string}
 */
var reverseParentheses = function (s) {
  let indStack = [];
  let res = [];

  for (let char_s of s) {
    if (char_s === "(") {
      indStack.push(res.length);
    } else if (char_s === ")") {
      let startInd = indStack.pop();
      let subArr = res.slice(startInd).reverse();
      res.splice(startInd, subArr.length, ...subArr);
    } else {
      res.push(char_s);
    }
  }

  return res.join("");
};
// @lc code=end
