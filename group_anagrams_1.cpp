#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
    vector<string> baseWords;
    vector<int> baseIndices;
    for (int i = 0; i < words.size(); i++) {
        string baseWord = words[i];
        sort(baseWord.begin(), baseWord.end());
        baseWords.push_back(baseWord);
        baseIndices.push_back(i);
    }
    sort(baseIndices.begin(), baseIndices.end(), [baseWords](int a, int b) -> bool {
        return baseWords[a] < baseWords[b];
    });

    vector<vector<string>> res;
    
}
