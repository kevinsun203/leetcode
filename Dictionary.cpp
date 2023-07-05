#include <vector>
#include <string>

struct TrieNode {
    std::vector<TrieNode*> children;
    bool endOfWord;

    TrieNode() : children(26, nullptr), endOfWord(false) {}
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(std::string word) {
        TrieNode* curr = root;

        for (int i=0; i<word.size(); i++) {
            // create child node if it doesn't exist
            if (curr->children[word[i]-'a'] == nullptr) {
                TrieNode* temp = new TrieNode();
                curr->children[word[i]-'a'] = temp;
            }

            curr = curr->children[word[i]-'a'];

            if (i==word.size()-1) {
                // Assign end of word
                curr->endOfWord = true;
            }
        }
    }
    
    bool search(std::string word) {
        TrieNode* curr = root;
        return searchNode(root, 0, word);
    }

    // root is a parent trie node and index marks the character to search for in the
    // node's children
    bool searchNode(TrieNode* root, int index, std::string& word) {
        // Check if the child exists
        if (root == nullptr) {
            return false;
        }

        // If we've reached the end of the word
        if (index == word.size()) {
            return root->endOfWord;
        }

        // Process the next letter
        if (word[index] != '.') {
            return searchNode(root->children[word[index]-'a'], index+1, word);
        } else {
            for (int i=0; i<26; i++) {
                if (searchNode(root->children[i], index+1, word)) {
                    return true;
                }
            }
            return false;
        }

    
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */