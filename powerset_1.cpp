#include <bits/stdc++.h>

using namespace std;

void generatePowerset(vector<vector<int>>& res, vector<int>& array, int idx) {
    if (idx == 0) {
        res.push_back({});
        return;
    }
    generatePowerset(res, array, idx - 1);
    vector<vector<int>> generated;
    for (auto set : res) {
        set.push_back(array[idx - 1]);
        generated.push_back(set);
    }
    res.insert(res.end(), generated.begin(), generated.end());
    return;
}

vector<vector<int>> powerset(vector<int> array) {
    vector<vector<int>> res;
    generatePowerset(res, array, array.size());
    return res;
}
