#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
    int n = array.size();
    sort(array.begin(), array.end());
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (array[i] + array[j] + array[k] == targetSum) {
                    res.push_back({array[i], array[j], array[k]});
                }
            }
        }
    }
    return res;
}
