/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int x, int color){
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=x) return;
        image[sr][sc] = color;
        dfs(image, sr+1, sc, x, color);
        dfs(image, sr, sc+1, x, color);
        dfs(image, sr-1, sc, x, color);
        dfs(image, sr, sc-1, x, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int x = image[sr][sc];
        if(x==color) return image;
        dfs(image, sr, sc, x, color);
        return image;
    }
};
// @lc code=end

