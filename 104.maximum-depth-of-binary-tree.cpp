/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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

    void dfs(TreeNode *root, int cnt)
    {
        if (root == nullptr)
        {
            ans = max(ans, cnt);
            return;
        }

        dfs(root->left, cnt + 1);
        dfs(root->right, cnt + 1);
    }
    int maxDepth(TreeNode *root)
    {
        dfs(root, 0);
        return ans;
    }
};
// @lc code=end
