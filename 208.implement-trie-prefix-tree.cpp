/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start

class TrieNode{
public:
    bool isWord;
    TrieNode* children[26];
    TrieNode(){
        isWord = false;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
       TrieNode* p = root;
       for(int i = 0; i < word.size(); i++){
           
           if(p->children[word[i] - 'a'] == NULL){
               p->children[word[i] - 'a'] = new TrieNode();
           }
           p = p->children[word[i] - 'a'];
       }
       p->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++){
            if(p->children[word[i] - 'a'] == NULL){
                return false;
            }
            p = p->children[word[i] - 'a'];
        }
        return p->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (int i = 0; i < prefix.size();i++)
        {
            if(p->children[prefix[i] - 'a'] == NULL){
                return false;
            }
            p = p->children[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

