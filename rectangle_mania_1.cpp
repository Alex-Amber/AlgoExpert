#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}
};

int getIdxFromPoint(Point coord) {
    return coord.x * 1000 + coord.y;
}

int rectangleMania(vector<Point> coords) {
    int n = coords.size();
    unordered_set<int> pointIdxes;
    for (Point coord: coords) {
        pointIdxes.insert(getIdxFromPoint(coord));
    }
    int x1, x2, y1, y2;
    int res = 0;
    for (int i = 0; i < n; i++) {
        x1 = coords[i].x;
        y1 = coords[i].y;
        for (int j = 0; j < n; j++) {
            if (!(x1 == coords[j].x && y1 < coords[j].y)) {
                continue;
            }
            for (int k = 0; k < n; k++) {
                if (!(y1 == coords[k].y && x1 < coords[k].x)) {
                    continue;
                }
                x2 = coords[k].x;
                y2 = coords[j].y;
                if (pointIdxes.count(getIdxFromPoint(Point(x2, y2)))) {
                    res++;
                }
            }
        }
    }
    return res;
}
