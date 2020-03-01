#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    int left = start, right = end;
    while (left <= right) {
        if (str[left] == str[right]) {
            left++;
            right--;
        } else {
            return false;
        }
    }
    return true;
}

string longestPalindromicSubstring(string str) {
    int start = 0, end = 0;
    for (int i = 0; i < str.size(); i++) {
        for (int j = i; j < str.size(); j++) {
            if (j - i + 1 > end - start + 1 && isPalindrome(str, i, j)) {
                start = i;
                end = j;
            }
        }
    }
    return str.substr(start, end - start + 1);
}
