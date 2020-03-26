#include <bits/stdc++.h>

using namespace std;

class ContinuousMedianHandler {
public:
    double median;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    void insert(int number) {
        int leftMedian = maxHeap.empty() ? INT_MIN : maxHeap.top();
        int rightMedian = minHeap.empty() ? INT_MAX : minHeap.top();
        if (number < leftMedian) {
            if (maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            maxHeap.push(number);
        } else if (number > rightMedian) {
            if (maxHeap.size() == minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            minHeap.push(number);
        } else {
            if (maxHeap.size() > minHeap.size()) {
                minHeap.push(number);
            } else {
                maxHeap.push(number);
            }
        }
        if (maxHeap.size() > minHeap.size()) {
            median = maxHeap.top();
        } else {
            median = (maxHeap.top() + minHeap.top()) / (double)2;
        }
        return;
    }

    double getMedian() {
        return median;
    }
};
