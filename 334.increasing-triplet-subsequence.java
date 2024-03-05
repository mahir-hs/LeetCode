/*
 * @lc app=leetcode id=334 lang=java
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start

class Solution {

    public boolean increasingTriplet(int[] nums) {

        int min1 = Integer.MAX_VALUE;
        int min2 = Integer.MAX_VALUE;
        for (int n : nums) {
            if (n <= min1) {
                min1 = n;
            } else if (n < min2) {
                min2 = n;
            } else if (n > min2) {
                return true;
            }
        }
        return false;
    }
}
// @lc code=end
