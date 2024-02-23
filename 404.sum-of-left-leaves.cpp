/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    void go(TreeNode *root, int x)
    {
        if (!root)
            return;

        if (root->left == nullptr and root->right == nullptr and x == 1)
            ans += root->val;
        go(root->left, 1);
        go(root->right, 0);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        go(root, 0);
        return ans;
    }
};
// @lc code=end
