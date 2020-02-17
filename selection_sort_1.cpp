#include <bits/stdc++.h>

using namespace std;

vector<int> selectionSort(vector<int> array) {
    int n = array.size();
    for (int i = 0; i < n; i++) {
        int smallest = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[smallest]) {
                smallest = j;
            }
        }
        swap(array[i], array[smallest]);
    }
    return array;
}
