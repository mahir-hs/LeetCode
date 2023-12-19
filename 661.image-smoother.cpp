/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        vector<vector<int>> ans(img.size(), vector<int>(img[0].size()));
        for (int i = 0; i < img.size(); i++)
        {
            for (int j = 0; j < img[0].size(); j++)
            {
                int cnt = 1;
                int sum = img[i][j];
                if (j + 1 < img[0].size())
                {
                    cnt++;
                    sum += img[i][j + 1];
                }
                if (i + 1 < img.size())
                {
                    cnt++;
                    sum += img[i + 1][j];
                }
                if (i + 1 < img.size() and j + 1 < img[0].size())
                {
                    cnt++;
                    sum += img[i + 1][j + 1];
                }

                if (j - 1 >= 0)
                {
                    cnt++;
                    sum += img[i][j - 1];
                }
                if (i + 1 < img.size() and j - 1 >= 0)
                {
                    cnt++;
                    sum += img[i + 1][j - 1];
                }
                if (i - 1 >= 0 and j - 1 >= 0)
                {
                    cnt++;
                    sum += img[i - 1][j - 1];
                }
                if (i - 1 >= 0)
                {
                    cnt++;
                    sum += img[i - 1][j];
                }
                if (i - 1 >= 0 and j + 1 < img[0].size())
                {
                    cnt++;
                    sum += img[i - 1][j + 1];
                }

                int now = sum / cnt;
                ans[i][j] = now;
            }
        }
        return ans;
    }
};
// @lc code=end
