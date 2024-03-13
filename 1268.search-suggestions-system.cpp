/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start

class TrieNode
{
public:
    vector<string> products;
    TrieNode *children[26];
    /**
     * This is the constructor for the TrieNode class. It initializes the 
     * children array and the products vector.
     *
     * The children array holds 26 pointers to other TrieNode objects. Each 
     * pointer represents a possible character in the trie. The array is 
     * initialized with NULL for each pointer, indicating that there are no 
     * nodes for each character initially.
     *
     * The products vector holds a list of strings. In the context of a trie, 
     * this vector is used to store words that have already been inserted into 
     * the trie. 
     *
     * The clear() function is called on the products vector to ensure that 
     * it is empty at the beginning of a new TrieNode.
     */
    TrieNode()
    {
        // Initialize the children array with NULL for each pointer
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        // Initialize the products vector to be empty
        products.clear();
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    /**
     * This is the constructor for the Trie class. It initializes the root
     * pointer to a new TrieNode object.
     *
     * @return
     *      None
     */
    Trie() : root(new TrieNode())
    {}

    /**
     * This function inserts a word into the trie. It takes a string word as 
     * input and inserts each character of the word into the trie. The 
     * function inserts the word into the trie node and also stores the word in 
     * the products vector of the trie node. The function keeps only the 
     * three most recent words added to the trie node in the products vector.
     *
     * @param word A string representing the word to be inserted into the trie.
     *
     * @return None.
     *
     * @throws None.
     */
    void insert(const std::string& word)
    {
        TrieNode* p = root;
        for (size_t i = 0; i < word.size(); i++)
        {
            if (p->children[word[i] - 'a'] == nullptr)
            {
                p->children[word[i] - 'a'] = new TrieNode();
            }

            p = p->children[word[i] - 'a'];
            p->products.push_back(word);
            if (p->products.size() > 3)
            {
                p->products.pop_back();
            }
        }
    }

    /**
     * This function suggests products based on a given prefix. It iterates over
     * each character in the prefix and traverses the trie to find the appropriate
     * trie node. If a trie node corresponding to a prefix character does not exist,
     * it means there are no products starting with that prefix, so it returns an
     * empty 2D vector. If a node does exist, it retrieves the products stored in
     * that node and returns them as a 2D vector.
     *
     * @param prefix A string representing the prefix for which we want to suggest
     * products.
     *
     * @return A 2D vector of strings. Each inner vector represents a set of
     * products starting with a prefix character. If no products exist, an empty
     * 2D vector is returned.
     *
     * @throws None.
     */
    vector<vector<string>> suggest(string prefix)
    {
        // Initialize a pointer to the root of the trie
        TrieNode *p = root;

        // Initialize a 2D vector to store the suggested products
        vector<vector<string>> ans(prefix.size());

        // Iterate over each character in the prefix
        for (int i = 0; i < prefix.size(); i++)
        {
            // Check if a trie node corresponding to the current prefix character exists
            if (p->children[prefix[i] - 'a'] == nullptr)
            {
                // If the node does not exist, return the empty 2D vector
                return ans;
            }

            // Move to the next node in the trie
            p = p->children[prefix[i] - 'a'];

            // Store the products associated with the current node in the 2D vector
            ans[i] = p->products;
        }

        // Return the suggested products
        return ans;
    }
};

class Solution
{
public:
    /**
     * This function takes in a vector of strings representing the products,
     * and a string representing the search word. It sorts the vector of
     * products in alphabetical order, creates a Trie data structure from
     * the products, and then uses the Trie to suggest products based on the
     * search word.
     *
     * @param products - A vector of strings representing the products
     * @param searchWord - A string representing the search word
     *
     * @return - A 2D vector of strings representing the suggested products
     */
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        // Sort the vector of products in alphabetical order
        sort(products.begin(), products.end());

        // Create a Trie data structure from the products
        Trie trie;
        for (auto i : products)
        {
            // Insert each product into the Trie
            trie.insert(i);
        }

        // Use the Trie to suggest products based on the search word
        return trie.suggest(searchWord);
    }
};
// @lc code=end
