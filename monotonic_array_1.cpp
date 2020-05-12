#include <bits/stdc++.h>

using namespace std;

bool isMonotonic(vector<int> array) {
    if (array.size() <= 2) {
        return true;
    }
    int trend = 0;
    if (array.front() < array.back()) {
        trend = 1;
    } else if (array.front() > array.back()) {
        trend = -1;
    }
    for (int i = 0; i < (int)array.size() - 1; i++) {
        switch (trend) {
            case 1: if (array[i] > array[i + 1]) {
                        return false;
                    }
                    break;
            case 0: if (array[i] != array[i + 1]) {
                        return false;
                    }
                    break;
            case -1: if (array[i] < array[i + 1]) {
                         return false;
                     }
                     break;
            default: break;
        }
    }
    return true;
}
