#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
    int n = array.size();
    sort(array.begin(), array.end());
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            if (array[i] + array[left] + array[right] > targetSum) {
                right--;
            }
            else if (array[i] + array[left] + array[right] < targetSum) {
                left++;
            }
            else {
                res.push_back({array[i], array[left], array[right]});
                left++;
                right--;
            }
        }
    }
    return res;
}
