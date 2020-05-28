#include <bits/stdc++.h>

using namespace std;

vector<int> mergeSortedArrays(vector<vector<int>> arrays) {
    int m = arrays.size();
    vector<int> indexes(m, 0), result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    for (int i = 0; i < m; i++) {
        heap.push(make_pair(arrays[i][0], i));
        indexes[i]++;
    }
    while (!heap.empty()) {
        int elem = heap.top().first, arrIdx = heap.top().second;
        heap.pop();
        result.push_back(elem);
        if (indexes[arrIdx] < arrays[arrIdx].size()) {
            heap.push(make_pair(arrays[arrIdx][indexes[arrIdx]], arrIdx));
            indexes[arrIdx]++;
        }
    }
    return result;
}
