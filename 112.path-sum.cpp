/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool go(TreeNode *root, int sum, int cnt)
    {
        if (!root)
            return false;

        if (cnt + root->val == sum and !root->left and !root->right)
            return true;

        return go(root->left, sum, cnt + root->val) || go(root->right, sum, cnt + root->val);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return go(root, targetSum, 0);
    }
};
// @lc code=end
