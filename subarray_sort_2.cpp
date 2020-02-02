#include <bits/stdc++.h>

using namespace std;

vector<int> subarraySort(vector<int> array) {
    int n = array.size();
    int left = 0, right = n - 1;
    while (left < n - 1 && array[left] <= array[left + 1]) {
        left++;
    }
    while (right > 0 && array[right] >= array[right - 1]) {
        right--;
    }
    if (left == n - 1) {
        return {-1, -1};
    }
    int max_val = INT_MIN, min_val = INT_MAX;
    for (int i = left; i <= right; i++) {
        max_val = max(max_val, array[i]);
        min_val = min(min_val, array[i]);
    }
    int subarray_left_idx = 0, subarray_right_idx = n - 1;
    while (subarray_left_idx < n && array[subarray_left_idx] <= min_val) {
        subarray_left_idx++;
    }
    while (subarray_right_idx >= 0 && array[subarray_right_idx] >= max_val) {
        subarray_right_idx--;
    }
    return {subarray_left_idx, subarray_right_idx};
}
