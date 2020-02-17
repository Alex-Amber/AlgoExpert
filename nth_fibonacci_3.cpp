#include <bits/stdc++.h>

using namespace std;

int getNthFib(int n) {
    int idx = 1;
    int first = 0, second = 1, cur = 0;
    while (idx < n) {
        first = second;
        second = cur;
        cur = first + second;
        idx++;
    }
    return cur;
}
