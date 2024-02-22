/*
 * @lc app=leetcode id=6 lang=java
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
    public String convert(String s, int numRows) {

        String[] ans = new String[numRows + 1];
        for (int i = 0; i <= numRows; i++)
            ans[i] = "";
        if (numRows == 1)
            return s;
            
        Integer counts = 1;
        boolean ok = false;

        for (int i = 0; i < s.length(); i++) {

            // System.out.println(counts);
            if (ok == false) {
                if (counts < numRows) {
                    ans[counts] += s.charAt(i);
                    counts++;
                } else {
                    ok = true;
                    ans[counts] += s.charAt(i);
                    counts--;
                }
            } else {

                if (counts > 1) {
                    ans[counts] += s.charAt(i);
                    counts--;
                } else {
                    ans[counts] += s.charAt(i);
                    ok = false;
                    counts++;
                }
            }
        }
        for (String k : ans) {
            System.out.println(k);
        }
        String x = String.join("", ans);
        return x;
    }
}
// @lc code=end
