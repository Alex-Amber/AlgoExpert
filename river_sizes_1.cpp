#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int floodFill(vector<vector<int>>& matrix, int r, int c, int s1, int s2) {
    int m = matrix.size(), n = matrix[0].size();
    queue<pair<int, int>> q;
    int count = 0;
    q.push(make_pair(r, c));
    matrix[r][c] = s2;
    while (!q.empty()) {
        int curX = q.front().first, curY = q.front().second;
        q.pop();
        count++;
        for (int i = 0; i < 4; i++) {
            int adjX = curX + dx[i], adjY = curY + dy[i];
            if (adjX < 0 || adjX >= m || adjY < 0 || adjY >= n || matrix[adjX][adjY] != s1) {
                continue;
            }
            q.push(make_pair(adjX, adjY));
            matrix[adjX][adjY] = s2;
        }
    }
    return count;
}

vector<int> riverSizes(vector<vector<int>> matrix) {
    vector<int> res;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 1) {
                res.push_back(floodFill(matrix, i, j, 1, 2));
            }
        }
    }
    return res;
}
