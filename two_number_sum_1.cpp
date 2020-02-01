#include <bits/stdc++.h>

using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
    int n = array.size();
    vector<int> res;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] + array[j] == targetSum) {
                res.push_back(array[i]);
                res.push_back(array[j]);
            }
        }
    }
    return res;
}
