#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
    unordered_map<string, vector<string>> anagrams;
    for (string& word : words) {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        anagrams[sortedWord].push_back(word);
    }
    vector<vector<string>> res;
    for (auto iter = anagrams.begin(); iter != anagrams.end(); iter++) {
        res.push_back(iter->second);
    }
    return res;
}
