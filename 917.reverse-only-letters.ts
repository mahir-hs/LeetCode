/*
 * @lc app=leetcode id=917 lang=typescript
 *
 * [917] Reverse Only Letters
 */

// @lc code=start
function reverseOnlyLetters(s: string): string {
  let arr = s.split("");
  let i: number = 0;
  let j: number = s.length - 1;
  while (i < j) {
    if (
      ((arr[i] >= "a" && arr[i] <= "z") || (arr[i] >= "A" && arr[i] <= "Z")) &&
      ((arr[j] >= "a" && arr[j] <= "z") || (arr[j] >= "A" && arr[j] <= "Z"))
    ) {
      [arr[i], arr[j]] = [arr[j], arr[i]];
      i++;
      j--;
    }
    if (!((arr[i] >= "a" && arr[i] <= "z") || (arr[i] >= "A" && arr[i] <= "Z")))
      i++;
    if (!((arr[j] >= "a" && arr[j] <= "z") || (arr[j] >= "A" && arr[j] <= "Z")))
      j--;
  }
  return arr.join("");
}
// @lc code=end
