/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    vector<int> ans;
    int cnt = 0, val = 0, max_ans = 0;
    void go(TreeNode *root)
    {
        if (!root)
            return;
        go(root->left);
        cnt = (val == root->val) ? cnt + 1 : 1;
        if (cnt == max_ans)
        {
            ans.push_back(root->val);
        }
        else if (cnt > max_ans)
        {
            max_ans = cnt;
            ans = {root->val};
        }
        val = root->val;
        go(root->right);
    }
    vector<int> findMode(TreeNode *root)
    {
        go(root);
        return ans;
    }
};
// @lc code=end
