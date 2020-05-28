#include <bits/stdc++.h>

using namespace std;

bool squareOfZeroes(vector<vector<int>> matrix) {
    int n = matrix.size();
    vector<vector<int>> sumLeftUpper(n, vector<int>(n, 0));
    sumLeftUpper[0][0] = matrix[0][0];
    for (int i = 1; i < n; i++) {
        sumLeftUpper[i][0] = matrix[i][0] + sumLeftUpper[i - 1][0];
    }
    for (int j = 1; j < n; j++) {
        sumLeftUpper[0][j] = matrix[0][j] + sumLeftUpper[0][j - 1];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            sumLeftUpper[i][j] = matrix[i][j] + sumLeftUpper[i - 1][j] + sumLeftUpper[i][j - 1] - sumLeftUpper[i - 1][j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int len = 2; len <= n; len++) {
                int x1 = i, y1 = j, x2 = i + len - 1, y2 = j + len - 1;
                if (x2 >= n || y2 >= n) {
                    continue;
                }
                int sumArea = sumLeftUpper[x2][y2] - (x1 > 0 ? sumLeftUpper[x1 - 1][y2] : 0) - (y1 > 0 ? sumLeftUpper[x2][y1 - 1] : 0) + (x1 > 0 && y1 > 0 ? sumLeftUpper[x1 - 1][y1 - 1] : 0);
                int sumInnerArea = 0;
                if (len > 2) {
                    sumInnerArea = sumLeftUpper[x2 - 1][y2 - 1] - sumLeftUpper[x1][y2 - 1] - sumLeftUpper[x2 - 1][y1] + sumLeftUpper[x1][y1];
                }
                if (sumArea == sumInnerArea) {
                    return true;
                }
            }
        }
    }
    return false;
}
