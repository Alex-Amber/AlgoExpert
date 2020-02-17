#include <bits/stdc++.h>
#include <any>

using namespace std;

int calculateProductSum(vector<any> array, int depth) {
    int res = 0;
    any integer = 1;
    for (auto elem : array) {
        if (elem.type() == integer.type()) {
            res += depth * any_cast<int>(elem);
        } else {
            res += depth * calculateProductSum(any_cast<vector<any>>(elem), depth + 1);
        }
    }
    return res;
}
  
int productSum(vector<any> array) {
    return calculateProductSum(array, 1);
}
