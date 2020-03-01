#include <bits/stdc++.h>

using namespace std;

string caesarCypherEncryptor(string str, int key) {
    string res;
    for (char ch : str) {
        char shiftedChar = (ch - 'a' + key) % 26 + 'a';
        res += shiftedChar;
    }
    return res;
}
