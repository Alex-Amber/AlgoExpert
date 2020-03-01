#include <bits/stdc++.h>

using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int coordX = 0, coordY = n - 1;
    while (coordX < m && coordY >= 0) {
        if (matrix[coordX][coordY] > target) {
            coordY--;
        } else if (matrix[coordX][coordY] < target) {
            coordX++;
        } else {
            return vector<int>({coordX, coordY});
        }
    }
    return vector<int>({-1, -1});
}
