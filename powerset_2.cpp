#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> powerset(vector<int> array) {
    vector<vector<int>> res({{}});
    for (int num : array) {
        int n = res.size();
        for (int i = 0; i < n; i++) {
            vector<int> set(res[i]);
            set.push_back(num);
            res.push_back(set);
        }
    }
    return res;
}
