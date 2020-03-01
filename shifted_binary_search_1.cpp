#include <bits/stdc++.h>

using namespace std;

int binarySearch(const vector<int>& array, int start, int end, int target) {
    int left = start, right = end, mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        if (array[mid] < target) {
            left = mid;
        } else {
            right = mid;
        }
    }
    if (array[right] == target) {
        return right;
    } else if (array[left] == target) {
        return left;
    } else {
        return -1;
    }
}

int shiftedBinarySearch(vector<int> array, int target) {
    int anchor = 1;
    while (anchor < array.size() && array[anchor - 1] <= array[anchor]) {
        anchor++;
    }
    int res = binarySearch(array, 0, anchor - 1, target);
    if (res == -1 && anchor < array.size()) {
        res = binarySearch(array, anchor, array.size() - 1, target);
    }
    return res;
}
