/*
 * @lc app=leetcode id=69 lang=golang
 *
 * [69] Sqrt(x)
 */

// @lc code=start
func mySqrt(x int) int {

	if x < 2 {
		return x
	}
	left, right := 2, x/2
	for left <= right {
		mid := left + (right-left)/2
		if mid*mid == x {
			return mid
		} else if mid*mid < x {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return right
}

// @lc code=end

