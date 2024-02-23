/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int ans = INT_MAX;
    void go(TreeNode *root, int cnt)
    {
        if (!root)
            return;
        if (root->left == nullptr and root->right == nullptr)
        {
            ans = min(ans, cnt);
        }
        go(root->left, cnt + 1);
        go(root->right, cnt + 1);
    }
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        go(root, 1);
        return ans;
    }
};
// @lc code=end
