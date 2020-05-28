#include <bits/stdc++.h>

using namespace std;

void helper(vector<int>& array, int startIdx, int endIdx, int k) {
    if (startIdx >= endIdx) {
        return;
    }
    int pivotIdx = startIdx;
    int leftIdx = startIdx + 1, rightIdx = endIdx;
    while (leftIdx <= rightIdx) {
        if (array[leftIdx] > array[pivotIdx] && array[rightIdx] < array[pivotIdx]) {
            swap(array[leftIdx], array[rightIdx]);
        }
        if (array[leftIdx] <= array[pivotIdx]) {
            leftIdx++;
        }
        if (array[rightIdx] >= array[pivotIdx]) {
            rightIdx--;
        }
    }
    swap(array[pivotIdx], array[rightIdx]);
    swap(pivotIdx, rightIdx);
    int leftStartIdx = startIdx, leftEndIdx = pivotIdx - 1;
    int rightStartIdx = pivotIdx + 1, rightEndIdx = endIdx;
    if (k > pivotIdx) {
        helper(array, rightStartIdx, rightEndIdx, k);
    } else if (k < pivotIdx) {
        helper(array, leftStartIdx, leftEndIdx, k);
    }
    return;
}

int quickselect(vector<int> array, int k) {
    k--;
    helper(array, 0, array.size() - 1, k);
    return array[k];
}
