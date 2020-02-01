#include <bits/stdc++.h>

using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
    sort(array.begin(), array.end());
    vector<int> res;
    for (int x : array) {
        int y = targetSum - x;
        if (x != y && binary_search(array.begin(), array.end(), y)) {
            res.push_back(x);
            res.push_back(y);
            break;
        }
    }
    return res;
}
