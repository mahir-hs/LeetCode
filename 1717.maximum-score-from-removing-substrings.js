/*
 * @lc app=leetcode id=1717 lang=javascript
 *
 * [1717] Maximum Score From Removing Substrings
 */

// @lc code=start
/**
 * @param {string} s
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var maximumGain = function (s, x, y) {
  let ans = 0;

  let top, bot;
  let top_score, bot_score;

  if (y > x) {
    top = "ba";
    top_score = y;
    bot = "ab";
    bot_score = x;
  } else {
    top = "ab";
    top_score = x;
    bot = "ba";
    bot_score = y;
  }

  let stack = [];

  for (let i = 0; i < s.length; i++) {
    if (
      s[i] === top[1] &&
      stack.length > 0 &&
      stack[stack.length - 1] === top[0]
    ) {
      ans += top_score;
      stack.pop();
    } else {
      stack.push(s[i]);
    }
  }

  let new_stack = [];
  for (let char of stack) {
    if (
      char == bot[1] &&
      new_stack.length > 0 &&
      new_stack[new_stack.length - 1] == bot[0]
    ) {
      ans += bot_score;
      new_stack.pop();
    } else {
      new_stack.push(char);
    }
  }

  return ans;
};
// @lc code=end
