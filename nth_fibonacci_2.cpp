#include <bits/stdc++.h>

using namespace std;

vector<int> memo;

int calculateNthFib(int n) {
    if (memo[n] > -1)
        return memo[n];
    return memo[n] = calculateNthFib(n - 2) + calculateNthFib(n - 1);
}

int getNthFib(int n) {
    memo = vector<int>(n + 1, -1);
    memo[1] = 0;
    memo[2] = 1;
    return calculateNthFib(n);
}
