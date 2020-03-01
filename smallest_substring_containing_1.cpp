#include <bits/stdc++.h>

using namespace std;

bool isContaining(unordered_map<char, int>& bigString, unordered_map<char, int>& smallString) {
    for (auto iter = smallString.begin(); iter != smallString.end(); iter++) {
        if (!bigString.count(iter->first) || bigString[iter->first] < iter->second) {
            return false;
        }
    }
    return true;
}

string smallestSubstringContaining(string bigString, string smallString) {
    int m = bigString.size(), n = smallString.size();
    int res_start = 0, res_len = INT_MAX;
    unordered_map<char, int> smallCharCounts;
    for (char ch: smallString) {
        smallCharCounts[ch]++;
    }
    for (int i = 0; i < m; i++) {
        for (int j = i + n - 1; j < m; j++) {
            unordered_map<char, int> bigCharCounts;
            for (int k = i; k <= j; k++) {
                bigCharCounts[bigString[k]]++;
            }
            if (isContaining(bigCharCounts, smallCharCounts) && j - i + 1 < res_len) {
                res_len = j - i + 1;
                res_start = i;
            }
        }
    }
    return res_len != INT_MAX ? bigString.substr(res_start, res_len) : "";
}
