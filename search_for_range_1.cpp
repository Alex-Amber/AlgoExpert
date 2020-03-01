#include <bits/stdc++.h>

using namespace std;

int searchLeftBound(const vector<int>& array, int target) {
    int left = 0, right = array.size() - 1, mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        if (array[mid] < target) {
            left = mid;
        } else {
            right = mid;
        }
    }
    if (array[left] == target) {
        return left;
    } else if (array[right] == target) {
        return right;
    } else {
        return -1;
    }
}

int searchRightBound(const vector<int>& array, int target) {
    int left = 0, right = array.size() - 1, mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        if (array[mid] <= target) {
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

vector<int> searchForRange(vector<int> array, int target) {
    int left = searchLeftBound(array, target);
    int right = searchRightBound(array, target);
    return vector<int>({left, right});
}
