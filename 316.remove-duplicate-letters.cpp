/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int>vis(26,0),cnt(26,0);
        stack<char>st;
        string ans;
        for(auto c:s)cnt[c-'a']++;
        for(auto c:s)
        {
            cnt[c-'a']--;
            if(vis[c-'a'])continue;
            while(!st.empty() and c<st.top() and cnt[st.top()-'a']>0)
            {
                vis[st.top()-'a']=0;
                st.pop();
            }
            vis[c-'a']=1;
            st.push(c);
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end
