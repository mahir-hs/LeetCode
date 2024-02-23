/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
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
    long long first = 1e18, second = 1e18;
    void go(TreeNode *root)
    {
        if (!root)
            return;

        if (root->val < first)
        {
            second = first;
            first = root->val;
        }
        else if (root->val > first and root->val < second)
        {
            second = root->val;
        }

        go(root->left);
        go(root->right);
    }
    int findSecondMinimumValue(TreeNode *root)
    {
        go(root);
        if (second == 1e18)
            return -1;
        // cout << first << " " << second << endl;
        return second;
    }
};
// @lc code=end
