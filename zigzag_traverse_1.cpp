#include <bits/stdc++.h>

using namespace std;

void traverseDiagonally(vector<vector<int>>& array, vector<int>& res, int diagonal_idx, bool x_start) {
    int m = array.size(), n = array[0].size();
    int x = 0, y = 0;
    if (x_start) {
        if (diagonal_idx >= n) {
            y = n - 1;
            x = diagonal_idx - y;
        }
        else {
            x = 0;
            y = diagonal_idx - x;
        }
        while (x < m && y >= 0) {
            res.push_back(array[x++][y--]);
        }
    }
    else {
        if (diagonal_idx >= m) {
            x = m - 1;
            y = diagonal_idx - x;
        }
        else {
            y = 0;
            x = diagonal_idx - y;
        }
        while (x >= 0 && y < n) {
            res.push_back(array[x--][y++]);
        }
    }
    return;
}

vector<int> zigzagTraverse(vector<vector<int>> array) {
    vector<int> res;
    int m = array.size(), n = array[0].size();
    bool x_start = true;
    for (int i = 0; i <= m + n - 2; i++) {
        traverseDiagonally(array, res, i, x_start);
        x_start = !x_start;
    }
    return res;
}
