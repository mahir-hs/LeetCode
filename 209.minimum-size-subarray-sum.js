/*
 * @lc app=leetcode id=209 lang=javascript
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
/**
 * @param {number} target
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function(target, nums) {
    
    let ans = Infinity;
    let sum = 0;
   let l = 0;
   let r = 0;
   while (r < nums.length) {
       sum += nums[r];
       while (sum >= target) {
           ans = Math.min(ans, r - l + 1);
           sum -= nums[l];
           l++;
       }
       r++;
   }
   return ans == Infinity ? 0 : ans;
};
// @lc code=end

