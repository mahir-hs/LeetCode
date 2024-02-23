/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
    unordered_map<int, pair<int, int>> m;
    void go(TreeNode *root, int cnt, int par)
    {
        if (!root)
            return;
        m[root->val] = {par, cnt};
        go(root->left, cnt + 1, root->val);
        go(root->right, cnt + 1, root->val);
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        go(root, 0, -1);

        return (m[x].first != m[y].first and m[x].second == m[y].second);
    }
};
// @lc code=end
