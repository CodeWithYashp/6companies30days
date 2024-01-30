class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> children;

    TrieNode() : isWord(false), children(26, nullptr) {}
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        addTrieWord(word, root);
    }

    bool search(string word) {
        return searchTrieWord(word, root);
    }

private:
    void addTrieWord(const string& word, TrieNode* root) {
        TrieNode* node = root;
        for (char c : word) {
            TrieNode* child = node->children[c - 'a'];
            if (child == nullptr) {
                child = new TrieNode();
            }
            node->children[c - 'a'] = child;
            node = child;
        }
        node->isWord = true;
    }

    bool searchTrieWord(const string& word, TrieNode* root) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (c == '.') {
                for (TrieNode* child : node->children) {
                    if (child != nullptr && searchTrieWord(word.substr(i + 1), child)) {
                        return true;
                    }
                }
                return false;
            }
            node = node->children[c - 'a'];
            if (node == nullptr) {
                return false;
            }
        }
        return node->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */