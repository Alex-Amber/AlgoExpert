#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string str) {
    vector<char> reversedArray;
    for (int i = 0; i < str.size(); i++) {
        reversedArray.push_back(str[str.size() - 1 - i]);
    }
    string reversed(reversedArray.begin(), reversedArray.end());
    return str == reversed;
}
