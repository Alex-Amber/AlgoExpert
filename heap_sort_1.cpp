#include <bits/stdc++.h>

using namespace std;

void buildMaxHeap(vector<int>& array) {
    
}

void siftDown(vector<int>& heap, int current_idx, int end_idx) {
    
}

vector<int> heapSort(vector<int> array) {
    buildMaxHeap(array);
    for (int end_idx = array.size() - 1; end_idx > 0; end_idx--) {
        swap(array[0], array[end_idx]);
        siftDown(array, 0, end_idx - 1);
    }
    return array;
}
