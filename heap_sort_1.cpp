#include <bits/stdc++.h>

using namespace std;

void siftDown(vector<int>& heap, int currentIdx, int endIdx) {
    int leftChildIdx = currentIdx * 2 + 1, rightChildIdx = currentIdx * 2 + 2;
    while (leftChildIdx <= endIdx) {
        if (heap[leftChildIdx] >= heap[currentIdx] && (rightChildIdx > endIdx || heap[leftChildIdx] >= heap[rightChildIdx])) {
            swap(heap[leftChildIdx], heap[currentIdx]);
            currentIdx = leftChildIdx;
        } else if (rightChildIdx <= endIdx && heap[rightChildIdx] >= heap[currentIdx] && heap[rightChildIdx] >= heap[leftChildIdx]) {
            swap(heap[rightChildIdx], heap[currentIdx]);
            currentIdx = rightChildIdx;
        } else {
            break;
        }
        leftChildIdx = currentIdx * 2 + 1;
        rightChildIdx = currentIdx * 2 + 2;
    }
    return;
}

void buildMaxHeap(vector<int>& array) {
    for (int currentIdx = array.size() - 1; currentIdx > 0; currentIdx--) {
        int parentIdx = floor((currentIdx - 1) / 2);
        siftDown(array, parentIdx, array.size() - 1);
    }
    return;
}

vector<int> heapSort(vector<int> array) {
    buildMaxHeap(array);
    for (int end_idx = array.size() - 1; end_idx > 0; end_idx--) {
        swap(array[0], array[end_idx]);
        siftDown(array, 0, end_idx - 1);
    }
    return array;
}
