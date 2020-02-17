#include <bits/stdc++.h>

using namespace std;

void generatePermutations(vector<vector<int>>& res, vector<int>& permutation, unordered_map<int, bool>& unpicked, int length) {
    if (permutation.size() == length) {
        res.push_back(permutation);
        return;
    }
    for (auto iter = unpicked.begin(); iter != unpicked.end(); iter++) {
        if (iter->second) {
            permutation.push_back(iter->first);
            iter->second = false;
            generatePermutations(res, permutation, unpicked, length);
            iter->second = true;
            permutation.pop_back();
        }
    }
    return;
}

vector<vector<int>> getPermutations(vector<int> array) {
    if (array.empty()) {
        return vector<vector<int>>();
    }
    unordered_map<int, bool> unpicked;
    for (int num : array) {
        unpicked[num] = true;
    }
    vector<vector<int>> res;
    vector<int> permutation;
    generatePermutations(res, permutation, unpicked, array.size());
    return res;
}
