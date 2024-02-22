/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
    int ans = 0;
    int go(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int val = root->val;
        int leftSum = go(root->left);
        int rightsum = go(root->right);
        ans +=  abs(leftSum - rightsum);
        return val + leftSum + rightsum;
    }
    int findTilt(TreeNode *root)
    {
        int x = go(root);
        return ans;
    }
};
// @lc code=end
