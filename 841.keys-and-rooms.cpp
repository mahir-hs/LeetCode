/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        bool mark[rooms.size()];
        memset(mark, false, sizeof mark);
        mark[0] = true;
        queue<int> q;
        
        for(auto k:rooms[0])
            q.push(k);
        
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            if(!mark[t])
            {
                mark[t] = true;
                for(auto k:rooms[t])
                    q.push(k);
            }
        }
        for(int i=0;i<rooms.size();i++)
            if(!mark[i])
                return false;
        return true;
    }
};
// @lc code=end

