#include <bits/stdc++.h>

using namespace std;

string longestSubstringWithoutDuplication(string str) {
    int longestStart = 0, longestLen = 0;
    int start = 0;
    vector<int> positions(26, -1);
    for (int i = 0; i < str.size(); i++) {
        int chIdx = str[i] - 'a';
        if (positions[chIdx] >= start) {
            if (i - start > longestLen) {
                longestLen = i - start;
                longestStart = start;
            }
            start = positions[chIdx] + 1;
            positions[chIdx] = i;
        } else {
            positions[chIdx] = i;
        }
    }
    if (str.size() - start > longestLen) {
        longestLen = str.size() - start;
        longestStart = start;
    }
    return str.substr(longestStart, longestLen);
}
