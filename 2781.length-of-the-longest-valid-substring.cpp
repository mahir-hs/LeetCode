/*
 * @lc app=leetcode id=2781 lang=cpp
 *
 * [2781] Length of the Longest Valid Substring
 */

// @lc code=start

class TrieNode
{
public:
    bool isWord;
    TrieNode *children[26];
    TrieNode()
    {
        isWord = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};
class Solution
{

    TrieNode *root;

public:

    Solution()
    {
        root = new TrieNode();
    }
    void insert(string word)
    {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++)
        {

            if (p->children[word[i] - 'a'] == NULL)
            {
                p->children[word[i] - 'a'] = new TrieNode();
            }
            p = p->children[word[i] - 'a'];
        }
        p->isWord = true;
    }
    bool search(string &word, int l, int r)
    {
        TrieNode *p = root;
        while (l <= r)
        {
            if (p->children[word[l] - 'a'] == NULL)
            {
                return false;
            }
            p = p->children[word[l] - 'a'];

            if (p->isWord)
                return true;
            l++;
        }
        return p->isWord;
    }
    int longestValidSubstring(string word, vector<string> &forbidden)
    {
        for (auto &k : forbidden)
            insert(k);

        int n = word.size();
        int r = n - 1;
        int ans = 0;
        for (int l = n - 1; l >= 0; l--)
        {
            while (l <= r and search(word, l, r))
                r--;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
// @lc code=end
