/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for(auto k:asteroids)
        {
            if(k>0)
                st.push(k);
            else
            {
                while(!st.empty() && st.top() > 0 && st.top() < abs(k))
                {
                    st.pop();
                }
                
                if(!st.empty() && st.top() == abs(k))
                    st.pop();
                else if(st.empty() || st.top()<abs(k))
                    st.push(k);
            }
        }

        vector<int> ans;

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

