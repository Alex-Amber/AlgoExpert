#include <bits/stdc++.h>

using namespace std;

void buildPattern(const string& substr, vector<int>& pattern) {
    int m = substr.size();
    pattern.assign(m, -1);
    int i = 1, j = 0;
    while (i < m) {
        if (substr[i] == substr[j]) {
            pattern[i] = j;
            i++;
            j++;
        } else if (j > 0) {
            j = pattern[j - 1] + 1;
        } else {
            pattern[i] = -1;
            i++;
        }
    }
    return;
}

bool doesMatch(const string& str, const string& substr, const vector<int>& pattern) {
    int m = substr.size(), n = str.size();
    int i = 0, j = 0;
    while (true) {
        if (str[i] == substr[j]) {
            i++;
            j++;
        } else if (j > 0) {
            j = pattern[j - 1] + 1;
        } else {
            i++;
        }
        if (j >= m) {
            return true;
        }
        if (i >= n) {
            return false;
        }
    }
}

bool knuthMorrisPrattAlgorithm(string str, string substr) {
    int m = substr.size(), n = str.size();
    vector<int> pattern;
    buildPattern(substr, pattern);
    return doesMatch(str, substr, pattern);
}
