#include <bits/stdc++.h>

using namespace std;

void quickSortHelper(vector<int>& array, int start_idx, int end_idx) {
    if (start_idx >= end_idx) {
        return;
    }
    int pivot_idx = start_idx;
    int left_idx = start_idx + 1, right_idx = end_idx;
    while (left_idx <= right_idx) {
        if (array[left_idx] > array[pivot_idx] && array[right_idx] < array[pivot_idx]) {
            swap(array[left_idx], array[right_idx]);
        }
        if (array[left_idx] <= array[pivot_idx]) {
            left_idx++;
        }
        if (array[pivot_idx] <= array[right_idx]) {
            right_idx--;
        }
    }
    swap(array[pivot_idx], array[right_idx]);
    swap(pivot_idx, right_idx);
    int left_start_idx = start_idx, left_end_idx = pivot_idx - 1;
    int right_start_idx = pivot_idx + 1, right_end_idx = end_idx;
    if (left_end_idx - left_start_idx < right_end_idx - right_start_idx) {
        quickSortHelper(array, left_start_idx, left_end_idx);
        quickSortHelper(array, right_start_idx, right_end_idx);
    } else {
        quickSortHelper(array, right_start_idx, right_end_idx);
        quickSortHelper(array, left_start_idx, left_end_idx);
    }
    return;
}

vector<int> quickSort(vector<int> array) {
    quickSortHelper(array, 0, array.size() - 1);
    return array;
}
