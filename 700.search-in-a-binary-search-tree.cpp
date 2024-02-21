/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
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
    TreeNode *searchBST(TreeNode *root, int val)
    {

        stack<TreeNode *> st;
        st.push(root);

        while (st.empty() == false)
        {
            TreeNode *now = st.top();
            st.pop();

            if (now->val == val)
                return now;
            if (now->left)
                st.push(now->left);
            if (now->right)
                st.push(now->right);
        }
        return nullptr;
    }
};
// @lc code=end
