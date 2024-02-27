/*
 * @lc app=leetcode id=345 lang=java
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start

import java.util.ArrayDeque;

class Solution {
    public String reverseVowels(String s) {

        ArrayDeque<Character> arr = new ArrayDeque<>();
        char[] x = s.toCharArray();
        StringBuilder ans = new StringBuilder();
        
        for (int i = 0; i < s.length(); i++) {
            Character c = Character.toLowerCase(s.charAt(i));
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                arr.add(s.charAt(i));
            }
        }
       
        for (int i = 0; i < s.length(); i++) {
            Character c = Character.toLowerCase(s.charAt(i));
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                x[i] = arr.getLast();
                arr.removeLast();
            }
            ans.append(x[i]);
        }
        String p = ans.toString();
        return p;

    }
}
// @lc code=end
