#include <bits/stdc++.h>

using namespace std;

bool isPalindromeHelper(const string& str, int left, int right) {
    if (left > right) {
        return true;
    }
    if (str[left] != str[right]) {
        return false;
    }
    return isPalindromeHelper(str, left + 1, right - 1);
}

bool isPalindrome(string str) {
    return isPalindromeHelper(str, 0, str.size() - 1);
}
