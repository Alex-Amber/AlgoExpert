#include <bits/stdc++.h>

using namespace std;

class MinHeap {
public:
    vector<int> heap;

    MinHeap(vector<int> vector) { heap = buildHeap(&vector); }

    vector<int> buildHeap(vector<int> *vector) {
        heap = *vector;
        for (int i = heap.size() - 1; i > 0; i--) {
            int parentIdx = floor((i - 1) / 2);
            siftDown(parentIdx, heap.size() - 1, &heap);
        }
        return heap;
    }

    void siftDown(int currentIdx, int endIdx, vector<int> *heap) {
        int leftChildIdx = currentIdx * 2 + 1, rightChildIdx = currentIdx * 2 + 2;
        while (leftChildIdx <= endIdx) {
            if (heap->at(leftChildIdx) <= heap->at(currentIdx) && (rightChildIdx > endIdx || heap->at(leftChildIdx) <= heap->at(rightChildIdx))) {
                swap(heap->at(leftChildIdx), heap->at(currentIdx));
                currentIdx = leftChildIdx;
            } else if (rightChildIdx <= endIdx && heap->at(rightChildIdx) <= heap->at(leftChildIdx) && heap->at(rightChildIdx) <= heap->at(currentIdx)) {
                swap(heap->at(rightChildIdx), heap->at(currentIdx));
                currentIdx = rightChildIdx;
            } else {
                break;
            }
            leftChildIdx = currentIdx * 2 + 1;
            rightChildIdx = currentIdx * 2 + 2;
        }
        return;
    }

    void siftUp(int currentIdx, vector<int> *heap) {
        while (currentIdx > 0) {
            int parentIdx = floor((currentIdx - 1) / 2);
            if (heap->at(parentIdx) > heap->at(currentIdx)) {
                swap(heap->at(parentIdx), heap->at(currentIdx));
                currentIdx = parentIdx;
            } else {
                break;
            }
        }
        return;
    }

    int peek() {
        if (heap.empty()) {
            return -1;
        }
        return heap[0];
    }

    int remove() {
        int root = peek();
        if (heap.empty()) {
            return root;
        }
        swap(heap[0], heap.back());
        heap.pop_back();
        siftDown(0, heap.size() - 1, &heap);
        return root;
    }

    void insert(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1, &heap);
        return;
    }
};
