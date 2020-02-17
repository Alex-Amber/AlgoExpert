#include <bits/stdc++.h>

using namespace std;

void mergeSubarrays(vector<int>& whole, vector<int>& left_sub, vector<int>& right_sub) {
    int i = 0, j = 0;
    while (i < left_sub.size() && j < right_sub.size()) {
        if (left_sub[i] < right_sub[j]) {
            whole[i + j] = left_sub[i];
            i++;
        } else {
            whole[i + j] = right_sub[j];
            j++;
        }
    }
    while (i < left_sub.size()) {
        whole[i + j] = left_sub[i];
        i++;
    }
    while (j < right_sub.size()) {
        whole[i + j] = right_sub[j];
        j++;
    }
    return;
}

void mergeSortHelper(vector<int>& array) {
    if (array.size() <= 1) {
        return;
    }
    int mid = (array.size() - 1) / 2;
    vector<int> left_subarray(array.begin(), array.begin() + mid + 1);
    vector<int> right_subarray(array.begin() + mid + 1, array.end());
    mergeSortHelper(left_subarray);
    mergeSortHelper(right_subarray);
    mergeSubarrays(array, left_subarray, right_subarray);
    return;
}

vector<int> mergeSort(vector<int> array) {
    mergeSortHelper(array);
    return array;
}
