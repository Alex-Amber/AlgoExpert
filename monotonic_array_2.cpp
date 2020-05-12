#include <bits/stdc++.h>

using namespace std;

int getDirection(int former, int latter) {
    if (latter > former) {
        return 1;
    } else if (latter < former) {
        return -1;
    } else {
        return 0;
    }
}

bool isMonotonic(vector<int> array) {
    int beforeDirection = 0;
    for (int i = 0; i < (int)array.size() - 1; i++) {
        int curDirection = getDirection(array[i], array[i + 1]);
        if (beforeDirection * curDirection < 0) {
            return false;
        }
        beforeDirection += curDirection;
    }
    return true;
}
