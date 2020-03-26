#include <bits/stdc++.h>

using namespace std;

int kadanesAlgorithm(vector<int> array) {
    int n = array.size();
    int res = INT_MIN, sum = 0;
    for (int num: array) {
        sum = max(sum + num, num);
        res = max(res, sum);
    }
    return res;
}
