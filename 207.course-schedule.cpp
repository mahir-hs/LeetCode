/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            numCourses--;
            for(int i = 0; i < adj[u].size(); i++){
                indegree[adj[u][i]]--;
                if(indegree[adj[u][i]] == 0) q.push(adj[u][i]);
            }
        }

        return numCourses == 0;
    }
};
// @lc code=end

