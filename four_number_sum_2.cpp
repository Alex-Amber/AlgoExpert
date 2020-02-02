#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
    int n = array.size();
    sort(array.begin(), array.end());
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int left = j + 1, right = n - 1;
            while (left < right) {
                if (array[i] + array[j] + array[left] + array[right] < targetSum) {
                    left++;
                }
                else if (array[i] + array[j] + array[left] + array[right] > targetSum) {
                    right--;
                }
                else {
                    res.push_back({array[i], array[j], array[left], array[right]});
                    left++;
                    right--;
                }
            }
        }
    }
    return res;
}
