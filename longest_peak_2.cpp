#include <bits/stdc++.h>

using namespace std;

int longestPeak(vector<int> array) {
    int n = array.size();
    int idx = 0, result = 0;
    while (idx < n) {
        int upLength = 0, downLength = 0;
        while (idx < n) {
            if (idx > 0 && array[idx] > array[idx - 1]) {
                upLength++;
            } else if (idx > 0 && array[idx] <= array[idx - 1]) {
                upLength = 0;
            }
            if (idx + 1 < n && array[idx] > array[idx + 1]) {
                break;
            }
            idx++;
        }
        idx++;
        while (idx < n) {
            if (array[idx - 1] <= array[idx]) {
                break;
            }
            downLength++;
            idx++;
        }
        if (upLength && downLength) {
            result = max(result, upLength + downLength + 1); 
        }
    }
    return result;
}
