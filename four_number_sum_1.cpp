#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
    int n = array.size();
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    if (array[i] + array[j] + array[k] + array[l] == targetSum) {
                        res.push_back({array[i], array[j], array[k], array[l]});
                    }
                }
            }
        }
    }
    return res;
}
