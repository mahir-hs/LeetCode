/*
 * @lc app=leetcode id=67 lang=golang
 *
 * [67] Add Binary
 */

// @lc code=start
func addBinary(a string, b string) string {

	n, m := len(a), len(b)

	if n < m {
		a = strings.Repeat("0", m-n) + a
	} else {
		b = strings.Repeat("0", n-m) + b
	}
	carry := 0
	result := ""
	for i := len(a) - 1; i >= 0; i-- {
		sum := int(a[i]-'0') + int(b[i]-'0') + carry
		result = string(sum%2+'0') + result
		carry = sum / 2
	}
	if carry > 0 {
		result = "1" + result
	}
	return result
}

// @lc code=end

