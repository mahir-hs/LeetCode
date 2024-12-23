/*
 * @lc app=leetcode id=3302 lang=cpp
 *
 * [3302] Find the Lexicographically Smallest Valid Sequence
 */

// @lc code=start
class Solution
{
public:
    vector<int> validSequence(string word1, string word2)
    {

        vector<int> ans;
        int x = word1.length();
        int y = word2.length();

        vector<int> arr(x, 0);
        int j = y - 1;
        for (int i = x - 1; i >= 0; i--)
        {
            if (i < x - 1)
                arr[i] = arr[i + 1];
            if (j >= 0 && word1[i] == word2[j])
            {
                arr[i]++;
                j--;
            }
        }
        j = 0;
        int cnt = 0;
        for (int i = 0; i < x && j < y; i++)
        {
            if (word1[i] == word2[j])
            {
                ans.push_back(i);
                j++;
                cnt++;
            }
            else if ((i < x - 1) && arr[i + 1] >= y - cnt - 1)
            {
                ans.push_back(i);
                cnt++;
                i++;
                j++;
                while (j < y)
                {
                    if (i >= x)
                        break;
                    if (word1[i] == word2[j])
                    {
                        ans.push_back(i);
                        j++;
                        cnt++;
                    }
                    i++;
                }
                return ans;
            }
        }

        if (cnt == y)
            return ans;
        return vector<int>();
    }
};
// @lc code=end
