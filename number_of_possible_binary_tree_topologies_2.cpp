#include <bits/stdc++.h>

using namespace std;

vector<int> memo;

int recursiveCountTopologies(int n) {
    if (memo[n] > 0) {
        return memo[n];
    }
    int num_topo = 0, num_sub_nodes = n - 1;
    for (int i = 0; i <= num_sub_nodes; i++) {
        num_topo += recursiveCountTopologies(i) * recursiveCountTopologies(num_sub_nodes - i);
    }
    return memo[n] = num_topo;
}

int numberOfBinaryTreeTopologies(int n) {
    memo = vector<int>(n + 1, 0);
    memo[0] = memo[1] = 1;
    return recursiveCountTopologies(n);
}
