#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    for (auto& interval: intervals) {
        if (!res.empty() && res.back()[1] >= interval[0]) {
            res.back().at(1) = max(res.back()[1], interval[1]);
        } else {
            res.push_back(interval);
        }
    }
    return res;
}

string underscorifySubstring(string str, string subStr) {
    int start = 0;
    vector<vector<int>> subStrRanges;
    while ((start = str.find(subStr, start)) != string::npos) {
        subStrRanges.push_back({start, start + (int)subStr.size()});
        start = start + 1;
    }
    vector<vector<int>> mergedRanges = mergeIntervals(subStrRanges);
    string res;
    int idx = 0;
    for (int i = 0; i < str.size(); i++) {
        if (idx < mergedRanges.size() && i == mergedRanges[idx][0]) {
            res.push_back('_');
        } else if (idx < mergedRanges.size() && i == mergedRanges[idx][1]) {
            res.push_back('_');
            idx++;
        }
        res.push_back(str[i]);
    }
    if (idx < mergedRanges.size() && str.size() == mergedRanges[idx][1]) {
        res.push_back('_');
    }
    return res;
}
