#include <bits/stdc++.h>

using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
    sort(arrayTwo.begin(), arrayTwo.end());
    int best_diff = INT_MAX;
    int num_one = 0, num_two = 0;
    for (int x : arrayOne) {
        vector<int>::iterator iter = lower_bound(arrayTwo.begin(), arrayTwo.end(), x);
        if (iter != arrayTwo.end()) {
            if (abs(x - *iter) < best_diff) {
                best_diff = abs(x - *iter);
                num_one = x;
                num_two = *iter;
            }
        }
        if (iter != arrayTwo.begin()) {
            if (abs(x - *prev(iter)) < best_diff) {
                best_diff = abs(x - *prev(iter));
                num_one = x;
                num_two = *prev(iter);
            }
        }
    }
    return {num_one, num_two};
}
