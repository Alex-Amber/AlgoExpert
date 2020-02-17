#include <bits/stdc++.h>

using namespace std;

vector<int> insertionSort(vector<int> array) {
    int n = array.size();
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (array[j - 1] > array[j]) {
                swap(array[j - 1], array[j]);
            } else {
                break;
            }
        }
    }
    return array;
}
