/*
 * @lc app=leetcode id=605 lang=java
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        if (n == 0)
            return true;
        if (flowerbed.length == 1) {
            if (flowerbed[0] == 0 && n == 1)
                return true;

            return false;
        }
        for (int i = 0; i < flowerbed.length; i++) {
            if (n == 0)
                break;
            if (i == 0 && i + 1 < flowerbed.length) {
                if (flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
                    n--;
                    flowerbed[i] = 1;
                }
                continue;
            }
            if (i + 1 == flowerbed.length && i - 1 >= 0) {
                if (flowerbed[i - 1] == 0 && flowerbed[i] == 0) {
                    n--;
                    flowerbed[i] = 1;
                }
                continue;
            }
            if (i + 1 < flowerbed.length && i - 1 >= 0)
                if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
                    n--;
                    flowerbed[i] = 1;
                }
        }
        if (n == 0)
            return true;
        return false;
    }
}
// @lc code=end
