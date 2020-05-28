#include <bits/stdc++.h>

using namespace std;

int waterArea(vector<int> heights) {
    if (heights.empty()) {
        return 0;
    }
    int n = heights.size();
    vector<int> leftBounds(n, 0), rightBounds(n, 0);
    leftBounds[0] = heights[0];
    for (int i = 1; i < n; i++) {
        leftBounds[i] = max(leftBounds[i - 1], heights[i]);
    }
    rightBounds[n - 1] = heights[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightBounds[i] = max(rightBounds[i + 1], heights[i]);
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += min(leftBounds[i], rightBounds[i]) - heights[i];
    }
    return result;
}
