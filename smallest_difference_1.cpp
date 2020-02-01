#include <bits/stdc++.h>

using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
    int best_diff = INT_MAX;
    int num_one = 0, num_two = 0;
    for (int i = 0; i < arrayOne.size(); i++) {
        for (int j = 0; j < arrayTwo.size(); j++) {
            if (abs(arrayOne[i] - arrayTwo[j]) < best_diff) {
                best_diff = abs(arrayOne[i] - arrayTwo[j]);
                num_one = arrayOne[i];
                num_two = arrayTwo[j];
            }
        }
    }
    return {num_one, num_two};
}
