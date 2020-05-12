#include <bits/stdc++.h>

using namespace std;

int getLeftSubtreeRootIdx(vector<int>& array, int rootIdx, int minValue, int maxValue) {
    int res = rootIdx + 1;
    while (res < array.size() && !(array[res] >= minValue && array[res] <= maxValue && array[res] < array[rootIdx])) {
        res++;
    }
    return res < array.size() ? res : -1;
}

int getRightSubtreeRootIdx(vector<int>& array, int rootIdx, int minValue, int maxValue) {
    int res = rootIdx + 1;
    while (res < array.size() && !(array[res] >= minValue && array[res] <= maxValue && array[res] >= array[rootIdx])) {
        res++;
    }
    return res < array.size() ? res : -1;
}

bool sameBstsHelper(vector<int>& arrayOne, vector<int>& arrayTwo, int rootIdxOne, int rootIdxTwo,
                    int minValue, int maxValue) {
    if (rootIdxOne == -1 && rootIdxTwo == -1) {
        return true;
    }
    if (rootIdxOne == -1 || rootIdxTwo == -1) {
        return false;
    }
    if (arrayOne[rootIdxOne] != arrayTwo[rootIdxTwo]) {
        return false;
    }
    int leftSubtreeRootIdxOne = getLeftSubtreeRootIdx(arrayOne, rootIdxOne, minValue, arrayOne[rootIdxOne] - 1);
    int rightSubtreeRootIdxOne = getRightSubtreeRootIdx(arrayOne, rootIdxOne, arrayOne[rootIdxOne], maxValue);
    int leftSubtreeRootIdxTwo = getLeftSubtreeRootIdx(arrayTwo, rootIdxTwo, minValue, arrayTwo[rootIdxTwo] - 1);
    int rightSubtreeRootIdxTwo = getRightSubtreeRootIdx(arrayTwo, rootIdxTwo, arrayTwo[rootIdxTwo], maxValue);
    return sameBstsHelper(arrayOne, arrayTwo, leftSubtreeRootIdxOne, leftSubtreeRootIdxTwo, minValue, arrayOne[rootIdxOne] - 1)
        && sameBstsHelper(arrayOne, arrayTwo, rightSubtreeRootIdxOne, rightSubtreeRootIdxTwo, arrayOne[rootIdxOne], maxValue);
}

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
    return sameBstsHelper(arrayOne, arrayTwo, 0, 0, INT_MIN, INT_MAX);
}