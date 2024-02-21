/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *go(vector<int> &nums, int b, int e)
    {
        if (b <= e)
        {
            int mid = b + (e - b) / 2;
            TreeNode *now = new TreeNode(nums[mid]);
            now->left = go(nums, b, mid - 1);
            now->right = go(nums, mid + 1, e);
            return now;
        }
        return nullptr;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {

        return go(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
