#include <bits/stdc++.h>

using namespace std;

vector<int> bubbleSort(vector<int> array) {
    int n = array.size(), num_swaps = 0;
    for (int i = 0; i < n; i++) {
        num_swaps = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                num_swaps++;
            }
        }
        if (num_swaps == 0) {
            break;
        }
    }
    return array;
}
