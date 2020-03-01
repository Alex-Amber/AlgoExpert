#include <bits/stdc++.h>

using namespace std;

string reverseXY(const string& pattern) {
    string res;
    for (char ch: pattern) {
        res.push_back(ch == 'x' ? 'y' : 'x');
    }
    return res;
}

bool isPatternMatched(const string& pattern, const string& str, const string& x, const string& y) {
    int cur = 0;
    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] == 'x') {
            for (int j = 0; j < x.size(); j++) {
                if (x[j] != str[cur]) {
                    return false;
                }
                cur++;
            }
        } else {
            for (int j = 0; j < y.size(); j++) {
                if (y[j] != str[cur]) {
                    return false;
                }
                cur++;
            }
        }
    }
    return true;
}

vector<string> patternMatcher(string pattern, string str) {
    bool startWithX = pattern[0] == 'x';
    if (!startWithX) {
        pattern = reverseXY(pattern);
    }
    int xPos = 0, yPos = 0;
    vector<int> counts(2, 0);
    for (int i = 0; i < pattern.size(); i++) {
        if (yPos == 0 && pattern[i] == 'y') {
            yPos = i;
        }
        counts[pattern[i] - 'x']++;
    }
    if (yPos == 0) {
        if (str.size() % counts[0] != 0) {
            return vector<string>();
        }
        string x = str.substr(0, str.size() / counts[0]);
        if (isPatternMatched(pattern, str, x, "")) {
            return startWithX ? vector<string>({x, ""}) : vector<string>({"", x});
        } else {
            return vector<string>();
        }
    }
    for (int i = 1; i < str.size(); i++) {
        for (int j = 1; j < str.size(); j++) {
            if (counts[0] * i + counts[1] * j != str.size()) {
                continue;
            }
            string x = str.substr(0, i);
            string y = str.substr(yPos * i, j);
            if (isPatternMatched(pattern, str, x, y)) {
                return startWithX ? vector<string>({x, y}) : vector<string>({y, x});
            }
        }
    }
    return vector<string>();
}
