#include "vector";
#include "string";
#include "unordered_map";
#include "algorithm";
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> answer;
        if (!s.length() || !p.length() || p.length() > s.length()) {
            return answer;
        }

        int sLength = s.length();
        int pLength = p.length();
        bool isAnagram = true;
        unordered_map<char, int> characters;

        // map of characters and their # of occurrences
        for (int i=0; i<pLength; i++) {
            if (characters.find(p[i]) == characters.end()) {
                characters.insert({p[i], 1});
            } else {
                characters[p[i]]++;
            }
        }

        // Frequency of first window
        for (int i=0; i<pLength; i++) {
            if (characters.find(s[i]) != characters.end()) {
                characters[s[i]]--;
            }
        }

        // frequency array
        vector<int*> frequency;

        // First window
        for (auto it=characters.begin(); it != characters.end(); it++) {
            frequency.push_back(&(it->second));
        }

        isAnagram = all_of(frequency.begin(), frequency.end(), [](int* i) { return *i==0; });
        if (isAnagram) {
            answer.push_back(0);
        }

        // Window slide
        for (int i=1; i<sLength-pLength+1; i++) {
            if (characters.find(s[i-1]) != characters.end()) {
                characters[s[i-1]]++;
            }
            if (characters.find(s[i+pLength-1]) != characters.end()) {
                characters[s[i+pLength-1]]--;
            }
            isAnagram = all_of(frequency.begin(), frequency.end(), [](int *i) { return *i==0; });

            if (isAnagram) {
                answer.push_back(i);
            }

        }
        return answer;
    }
};