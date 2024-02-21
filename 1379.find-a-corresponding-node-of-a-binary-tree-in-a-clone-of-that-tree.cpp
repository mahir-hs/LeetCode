/*
 * @lc app=leetcode id=1379 lang=cpp
 *
 * [1379] Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {

        stack<TreeNode*> st;
        st.push(cloned);
        while (st.empty() == false)
        {
            TreeNode *now = st.top();
            st.pop();

            if (now->val == target->val)
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
