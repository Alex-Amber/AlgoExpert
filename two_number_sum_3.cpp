#include <bits/stdc++.h>

using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
    unordered_set<int> nums;
    for (int num : array) {
        nums.insert(num);
    }
    vector<int> res;
    for (int x : array) {
        int y = targetSum - x;
        if (x != y && nums.count(y)) {
            res.push_back(x);
            res.push_back(y);
            break;
        }
    }
    return res;
}
