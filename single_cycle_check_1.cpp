#include <bits/stdc++.h>

using namespace std;

int getNextIdx(int currentIdx, vector<int>& array) {
    int n = array.size();
    int step = array[currentIdx] >= 0 ? array[currentIdx] : (n + array[currentIdx] % n);
    return (currentIdx + step) % n;
}

bool hasSingleCycle(vector<int> array) {
    int n = array.size();
    int numVisited = 0, currentIdx = 0;
    while (numVisited < n) {
        if (numVisited > 0 && currentIdx == 0) {
            return false;
        }
        currentIdx = getNextIdx(currentIdx, array);
        numVisited++;
    }
    return currentIdx == 0;
}
