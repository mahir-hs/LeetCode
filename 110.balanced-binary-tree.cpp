/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool ans = true;

    int go(TreeNode *root)
    {
        if (!root)
            return 0;
        if (ans == false)
            return 0;

        int left = go(root->left);
        int right = go(root->right);
        if (abs(left - right) > 1)
            ans = false;

        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;

        go(root);

        return ans;
    }
};
// @lc code=end
