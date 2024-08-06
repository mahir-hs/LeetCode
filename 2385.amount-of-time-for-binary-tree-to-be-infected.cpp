/*
 * @lc app=leetcode id=2385 lang=cpp
 *
 * [2385] Amount of Time for Binary Tree to Be Infected
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
    TreeNode *startNode = NULL;
    unordered_map<int, TreeNode *> mp;
    int totalNode = 0;
    void dfs(TreeNode *root, int start)
    {

        if (root == NULL)
            return;
        if (root->val == start)
            startNode = root;
        if (root->left)
            mp[root->left->val] = root;
        if (root->right)
            mp[root->right->val] = root;
        dfs(root->left, start);
        dfs(root->right, start);
        totalNode++;
    }
    int amountOfTime(TreeNode *root, int start)
    {

        dfs(root, start);
        queue<TreeNode *> q;
        q.push(startNode);
        int ans = 0;
        unordered_set<int> vis;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (vis.count(node->val))
                    continue;
                vis.insert(node->val);
                if (vis.size() == totalNode)
                    return ans;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                if (mp[node->val])
                    q.push(mp[node->val]);
            }
            ans++;
        }
        return 0;
    }
};
// @lc code=end
