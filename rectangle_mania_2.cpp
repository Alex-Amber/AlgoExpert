#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}
};

int getIdxFromPoint(const Point& p) {
    return p.x * 1000 + p.y;
}

int rectangleMania(vector<Point> coords) {
    int n = coords.size();
    unordered_set<int> pointIndices;
    for (auto& coord: coords) {
        pointIndices.insert(getIdxFromPoint(coord));
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (coords[j].x > coords[i].x && coords[j].y > coords[i].y) {
                int x1 = coords[i].x, y1 = coords[i].y;
                int x2 = coords[j].x, y2 = coords[j].y;
                Point k(x1, y2), l(x2, y1);
                res += pointIndices.count(getIdxFromPoint(k)) && pointIndices.count(getIdxFromPoint(l));
            }
        }
    }
    return res;
}
