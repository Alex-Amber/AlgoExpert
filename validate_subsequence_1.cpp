#include <bits/stdc++.h>

using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    int m = array.size(), n = sequence.size();
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (array[i] == sequence[j]) {
            j++;
        }
        i++;
    }
    return j == n;
}
