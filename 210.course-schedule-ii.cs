/*
 * @lc app=leetcode id=210 lang=csharp
 *
 * [210] Course Schedule II
 */

// @lc code=start
public class Solution {
    public int[] FindOrder(int numCourses, int[][] prerequisites) {
        int[] ans = new int[numCourses];
        int[] indegree = new int[numCourses];

        List<List<int>> adj = new List<List<int>>();
        for (int i = 0; i < numCourses; i++)
            adj.Add(new List<int>());

        for (int i = 0; i < prerequisites.Length; i++)  {
            adj[prerequisites[i][1]].Add(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        Queue<int> q = new Queue<int>();
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                q.Enqueue(i);

        int idx = 0;
        while (q.Count > 0) {
            int u = q.Dequeue();
            ans[idx++] = u;
            foreach (int v in adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.Enqueue(v);
            }
        }

        if (idx != numCourses)
            return new int[0];
        return ans;

    }
}
// @lc code=end

