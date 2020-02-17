#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

bool compareStrings(string& one, string& two, string& three,
                    int idx_one, int idx_two, int idx_three) {
    if (idx_three == three.size()) {
        return idx_one == one.size() && idx_two == two.size();
    }
    if (memo[idx_one][idx_two] > -1) {
        return (bool)memo[idx_one][idx_two];
    }
    bool res = false;
    if ((idx_one < one.size() && three[idx_three] == one[idx_one]) && (idx_two < two.size() && three[idx_three] == two[idx_two])) {
        res = res || compareStrings(one, two, three, idx_one + 1, idx_two, idx_three + 1);
        res = res || compareStrings(one, two, three, idx_one, idx_two + 1, idx_three + 1);
    } else if (idx_one < one.size() && three[idx_three] == one[idx_one]) {
        res = res || compareStrings(one, two, three, idx_one + 1, idx_two, idx_three + 1);
    } else if (idx_two < two.size() && three[idx_three] == two[idx_two]) {
        res = res || compareStrings(one, two, three, idx_one, idx_two + 1, idx_three + 1);
    }
    memo[idx_one][idx_two] = (int)res;
    return res;
}

bool interweavingStrings(string one, string two, string three) {
    int m = one.size(), n = two.size();
    memo = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
    return compareStrings(one, two, three, 0, 0, 0);
}
