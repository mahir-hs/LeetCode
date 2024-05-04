/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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

    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            int cnt = q.size();
            while (cnt--)
            {
                TreeNode *now = q.front();
                q.pop();
                if (now->left)
                    q.push(now->left);
                if (now->right)
                    q.push(now->right);
                if (cnt == 0)
                    ans.push_back(now->val);
            }
        }
        return ans;
    }
};
// @lc code=end
