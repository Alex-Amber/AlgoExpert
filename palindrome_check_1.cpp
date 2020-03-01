#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string str) {
    string reversed;
    for (int i = str.size() - 1; i >= 0; i--) {
        reversed += str[i];
    }
    return str == reversed;
}
