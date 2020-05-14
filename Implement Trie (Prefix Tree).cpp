class Trie {
   public:
    /** Initialize your data structure here. */
    Trie* children[26];
    bool end;
    Trie() {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
        end = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.length();
        Trie* node = this;
        for (int i = 0; i < n; ++i) {
            if (!node->children[word[i] - 'a']) {
                node->children[word[i] - 'a'] = new Trie();
            }
            node = node->children[word[i] - 'a'];
        }
        node->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.length();
        Trie* node = this;
        for (int i = 0; i < n; ++i) {
            if (!node->children[word[i] - 'a']) return false;
            node = node->children[word[i] - 'a'];
        }
        return node->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        int n = word.length();
        Trie* node = this;
        for (int i = 0; i < n; ++i) {
            if (!node->children[word[i] - 'a']) return false;
            node = node->children[word[i] - 'a'];
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