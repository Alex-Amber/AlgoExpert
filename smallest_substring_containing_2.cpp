#include <bits/stdc++.h>

using namespace std;

string smallestSubstringContaining(string bigString, string smallString) {
    int m = bigString.size(), n = smallString.size();
    unordered_map<char, int> smallTable;
    for (char ch: smallString) {
        smallTable[ch] += 1;
    }
    int l = 0, r = -1;
    unordered_map<char, int> rangeTable;
    int numInvalid = smallTable.size();
    int resultStart = -1, resultLength = INT_MAX;
    bool validFlag = false;
    while (true) {
        if (!validFlag) {
            r++;
            if (r >= m) {
                break;
            }
            char ch = bigString[r];
            if (smallTable.count(ch) && rangeTable[ch] == smallTable[ch] - 1) {
                numInvalid--;
            }
            rangeTable[ch]++;
        } else {
            l++;
            char ch = bigString[l - 1];
            if (smallTable.count(ch) && rangeTable[ch] == smallTable[ch]) {
                numInvalid++;
            }
            rangeTable[ch]--;
        }
        validFlag = !numInvalid;
        if (validFlag && r - l + 1 < resultLength) {
            resultLength = r - l + 1;
            resultStart = l;
        }
    }
    if (resultStart >= 0) {
        return bigString.substr(resultStart, resultLength);
    } else {
        return "";
    }
}