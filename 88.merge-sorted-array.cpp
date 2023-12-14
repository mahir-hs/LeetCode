/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        int a = m - 1;
        int b = n - 1;
        int cur = a + b + 1;
        while (a >= 0 && b >= 0)
        {
            if (nums1[a] > nums2[b])
            {
                nums1[cur--] = nums1[a--];
            }
            else
            {
                nums1[cur--] = nums2[b--];
            }
        }
        while (b >= 0)
            nums1[cur--] = nums2[b--];
    }
};
// @lc code=end

