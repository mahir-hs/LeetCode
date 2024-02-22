/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int go(TreeNode *root, int &cnt)
    {
        if (!root)
            return 0;

        int left = go(root->left, cnt);
        int right = go(root->right, cnt);
        cnt = max(cnt, left + right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int cnt = 0;
        go(root, cnt);

        return cnt;
    }
};
// @lc code=end
