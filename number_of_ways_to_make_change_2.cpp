#include <bits/stdc++.h>

using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
    vector<int> counts(n + 1, 0);
    counts[0] = 1;
    for (int denom : denoms) {
        for (int i = denom; i <= n; i++) {
            counts[i] += counts[i - denom];
        }
    }
    return counts[n];
}
