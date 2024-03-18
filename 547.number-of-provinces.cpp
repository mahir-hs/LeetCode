/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:

    void dfs(vector<vector<int>>& isConnected,int i,bool visited[])
    {
        visited[i]=true;
        for(int j=0;j<isConnected.size();j++)
        {
            if(isConnected[i][j]==1 && visited[j]==false)
            {
                dfs(isConnected,j,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        bool visited[isConnected.size()];
        memset(visited,false,sizeof (visited));

        int count=0;

        for(int i=0;i<isConnected.size();i++)
        {
            if(visited[i]==false)
            {
                dfs(isConnected,i,visited);
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

