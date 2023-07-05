#include <vector>
#include <string>

struct TrieNode {
    std::vector<TrieNode*> children; // Store all the children along with their
                                     // corresponding node pointers
    bool endOfWord = false;
    TrieNode() : children(26, nullptr), endOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();  
    }
    
    void insert(std::string word) {
        TrieNode* curr = root;

        for (int i=0; i<word.size(); i++) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                // create new node if not a child
                TrieNode* temp = new TrieNode();
                curr->children[word[i]-'a'] = temp;
            }
            curr = curr->children[word[i]-'a'];

            // Set end of word
            if (i == word.size()-1) {
                curr->endOfWord = true;
            }
        }
    }
    
    bool search(std::string word) {
        TrieNode* curr = root;
        for (int i=0; i<word.size(); i++) {
            if (curr->children[word[i]-'a'] == nullptr) {
                return false;
            }
            curr = curr->children[word[i]-'a'];
            if (i == word.size() - 1) {
                return curr->endOfWord;
            }
        }
        return false;
    }
    
    bool startsWith(std::string prefix) {
        TrieNode* curr = root;

        for (int i=0; i<prefix.size(); i++) {
            if (curr->children[prefix[i]-'a'] == nullptr) {
                return false;
            }
            curr = curr->children[prefix[i]-'a'];
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