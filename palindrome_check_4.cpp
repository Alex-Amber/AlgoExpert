#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string str) {
    int left = 0, right = str.size() - 1;
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
