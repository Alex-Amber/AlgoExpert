#include <bits/stdc++.h>

using namespace std;

int longestPeak(vector<int> array) {
    int n = array.size();
    int idx = 0, result = 0;
    while (idx < n) {
        if (idx > 0 && idx < n - 1 && array[idx - 1] < array[idx] && array[idx] > array[idx + 1]) {
            int length = 1, left = idx, right = idx;
            while (left > 0 && array[left - 1] < array[left]) {
                left--;
                length++;
            }
            while (right < n - 1 && array[right] > array[right + 1]) {
                right++;
                length++;
            }
            result = max(result, length);
            idx = right;
        }
        idx++;
    }
    return result;
}
