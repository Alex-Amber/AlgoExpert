#include <bits/stdc++.h>

using namespace std;

pair<int, int> expandPalindromicString(const string& str, int left, int right) {
    while (left - 1 >= 0 && right + 1 < str.size() && str[left - 1] == str[right + 1]) {
        left--;
        right++;
    }
    return make_pair(left, right);
}

string longestPalindromicSubstring(string str) {
    int n = str.size();
    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        pair<int, int> range = expandPalindromicString(str, i, i);
        if (range.second - range.first + 1 > end - start + 1) {
            start = range.first;
            end = range.second;
        }
        if (i + 1 < n && str[i] == str[i + 1]) {
            range = expandPalindromicString(str, i, i + 1);
            if (range.second - range.first + 1 > end - start + 1) {
                start = range.first;
                end = range.second;
            }
        }
    }
    return str.substr(start, end - start + 1);
}
