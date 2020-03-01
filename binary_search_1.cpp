#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> array, int target) {
    int n = array.size();
    int left = 0, right = n - 1, mid;
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
