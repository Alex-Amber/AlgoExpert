#include <bits/stdc++.h>

using namespace std;

bool isStringWithoutDuplication(const string& str, int start, int end) {
    vector<int> counts(26, 0);
    for (int i = start; i <= end; i++) {
        counts[str[i] - 'a']++;
        if (counts[str[i] - 'a'] > 1) {
            return false;
        }
    }
    return true;
}

string longestSubstringWithoutDuplication(string str) {
    int start = 0, end = 0;
    int n = str.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j - i + 1 > end - start + 1 && isStringWithoutDuplication(str, i, j)) {
                start = i;
                end = j;
            }
        }
    }
    return str.substr(start, end - start + 1);
}
