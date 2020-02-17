#include <bits/stdc++.h>

using namespace std;

int numberOfBinaryTreeTopologies(int n) {
    vector<int> memo(n + 1, 0);
    memo[0] = memo[1] = 1;
    for (int i = 2; i <= n; i++) {
        int num_sub_nodes = i - 1;
        for (int j = 0; j <= num_sub_nodes; j++) {
            int k = num_sub_nodes - j;
            memo[i] += memo[j] * memo[k];
        }
    }
    return memo[n];
}
