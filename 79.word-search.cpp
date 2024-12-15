/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool helper(vector<vector<char>>& board,string word,int i,int j,int k){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[k]){
            return false;
        }
        if(k==word.size()-1){
            return true;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool ans = helper(board,word,i+1,j,k+1) || helper(board,word,i-1,j,k+1) || helper(board,word,i,j+1,k+1) || helper(board,word,i,j-1,k+1);
        board[i][j] = temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && helper(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
        
    }
};
// @lc code=end

