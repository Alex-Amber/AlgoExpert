#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
    int n = array.size();
    sort(array.begin(), array.end());
    unordered_map<int, int> positions;
    for (int i = 0; i < n; i++) {
        positions[array[i]] = i;
    }
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int z = targetSum - array[i] - array[j];
            if (positions.count(z) && positions[z] > j) {
                res.push_back({array[i], array[j], z});
            }
        }
    }
    return res;
}
