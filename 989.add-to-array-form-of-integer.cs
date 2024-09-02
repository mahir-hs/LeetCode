/*
 * @lc app=leetcode id=989 lang=csharp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
public class Solution {
    public IList<int> AddToArrayForm(int[] num, int k) {

        int i = num.Length - 1;
        int j = k;
        int carry = 0;
        List<int> ans = new List<int>();
        while (i >= 0 || j > 0 || carry > 0)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += num[i];
                i--;
            }
            if (j > 0)
            {
                sum += j % 10;
                j = j / 10;
            }
            ans.Add(sum % 10);
            carry = sum / 10;
        }

        ans.Reverse();

        return ans;
    }
}
// @lc code=end

