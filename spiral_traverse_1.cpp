#include <bits/stdc++.h>

using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
    int m = array.size(), n = array[0].size();
    vector<int> result;
    int left = 0, right = n - 1, up = 0, bottom = m - 1;
    while (left < right && up < bottom) {
        int x = up, y = left;
        while (x == up && y < right) {
            result.push_back(array[x][y]);
            y++;
        }
        while (y == right && x < bottom) {
            result.push_back(array[x][y]);
            x++;
        }
        while (x == bottom && y > left) {
            result.push_back(array[x][y]);
            y--;
        }
        while (y == left && x > up) {
            result.push_back(array[x][y]);
            x--;
        }
        left++;
        right--;
        up++;
        bottom--;
    }
    if (left == right) {
        for (int i = up; i <= bottom; i++) {
            result.push_back(array[i][left]);
        }
    } else if (up == bottom) {
        for (int j = left; j <= right; j++) {
            result.push_back(array[up][j]);
        }
    }
    return result;
}
