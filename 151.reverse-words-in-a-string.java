/*
 * @lc app=leetcode id=151 lang=java
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
    public String reverseWords(String s) {

        StringBuilder ans = new StringBuilder();
        StringBuilder temp = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; i--) {

            if (s.charAt(i) == ' ') {

                if (temp.length() > 0) {
                    temp.reverse();
                    if (ans.length() > 0)
                        ans.append(" ");
                    ans.append(temp);
                    temp.setLength(0);
                }
            } else {
                temp.append(s.charAt(i));
            }
        }
        if (temp.length() > 0) {
            temp.reverse();
            if (ans.length() > 0)
                ans.append(" ");
            ans.append(temp);
        }

        s = ans.toString();
        return s;
    }
}
// @lc code=end
