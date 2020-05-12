#include <bits/stdc++.h>

using namespace std;

bool isNonDecreasing(vector<int>& array) {
    for (int i = 0; i < (int)array.size() - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

bool isNonIncreasing(vector<int>& array) {
    for (int i = 0; i < (int)array.size() - 1; i++) {
        if (array[i] < array[i + 1]) {
            return false;
        }
    }
    return true;
}

bool isMonotonic(vector<int> array) {
    return isNonDecreasing(array) || isNonIncreasing(array);
}
