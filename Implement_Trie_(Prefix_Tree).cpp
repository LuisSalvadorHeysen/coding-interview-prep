// https://leetcode.com/problems/implement-trie-prefix-tree/

const int ALPHABET = 26;

class Trie {
public:
    struct trieNode {
        trieNode *children[ALPHABET];
        int terminal;
    };

    trieNode *new_node() {
        trieNode *new_node = new trieNode;
        new_node->terminal = 0;
        for (int i = 0; i < ALPHABET; ++i) {
            new_node->children[i] = NULL;
        }
        return new_node;
    }

    void insert(trieNode *root, string word) {
        trieNode *node = root;
        for (char c : word) {
            int idx = int(c - 'a');
            if (!node->children[idx]) {
                node->children[idx] = new_node();
            }
            node = node->children[idx];
        }
        ++node->terminal;
    }

    bool search(trieNode *root, string word) {
        trieNode *node = root;
        for (char c : word) {
            int idx = int(c - 'a');
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }

        return node && node->terminal;
    } 

    bool starts_with(trieNode *root, string word) {
        trieNode *node = root;
        for (char c : word) {
            int idx = int(c - 'a');
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }

        return node;
    } 

    trieNode *trie;

    Trie() {
        trie = new_node();
    }
    
    void insert(string word) {
        insert(trie, word);
    }
    
    bool search(string word) {
        return search(trie, word);
    }
    
    bool startsWith(string prefix) {
        return starts_with(trie, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
