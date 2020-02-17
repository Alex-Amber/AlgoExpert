#include <bits/stdc++.h>

using namespace std;

int numberOfBinaryTreeTopologies(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int num_sub_nodes = n - 1;
    int num_topo = 0;
    for (int i = 0; i <= num_sub_nodes; i++) {
        num_topo += numberOfBinaryTreeTopologies(i) * numberOfBinaryTreeTopologies(num_sub_nodes - i);
    }
    return num_topo;
}
