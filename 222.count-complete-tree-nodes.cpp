/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode *root)
    {

        vector<TreeNode *> v;
        int ans = 0;
        if(root==nullptr)
            return 0;
        queue<TreeNode *> q;

        q.push(root);
        while (q.empty() == false)
        {
            ans += q.size();
            int cnt = q.size();
            for (int i = 0; i < cnt; i++)
            {
                TreeNode *now = q.front();
                q.pop();
                if (now->left)
                    q.push(now->left);
                if (now->right)
                    q.push(now->right);
            }
        }
        return ans;
    }
};
// @lc code=end
