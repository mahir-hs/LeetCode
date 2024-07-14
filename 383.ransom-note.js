/*
 * @lc app=leetcode id=383 lang=javascript
 *
 * [383] Ransom Note
 */

// @lc code=start
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function (ransomNote, magazine) {
  let m = new Map();
  for (let i = 0; i < magazine.length; i++) {
    if (m.has(magazine[i])) {
      m.set(magazine[i], m.get(magazine[i]) + 1);
    } else {
      m.set(magazine[i], 1);
    }
  }

  for (let i = 0; i < ransomNote.length; i++) {
    if (m.has(ransomNote[i]) && m.get(ransomNote[i]) > 0) {
      m.set(ransomNote[i], m.get(ransomNote[i]) - 1);
    } else {
      return false;
    }
  }
  return true;
};
// @lc code=end
