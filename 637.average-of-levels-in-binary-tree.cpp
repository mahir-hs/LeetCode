/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode *root)
    {

        queue<TreeNode *> q;
        vector<double> ans;
        q.push(root);
        while (q.empty() == false)
        {
            queue<TreeNode *> p, pp;
            p = q;
            q = pp;
            double now = 0, cnt = 0;
            while (p.empty() == false)
            {
                TreeNode *x = p.front();
                p.pop();
                cnt++;
                now += x->val;
                if (x->left)
                    q.push(x->left);
                if (x->right)
                    q.push(x->right);
            }
            ans.push_back(now / cnt);
        }
        return ans;
    }
};
// @lc code=end
