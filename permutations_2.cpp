#include <bits/stdc++.h>

using namespace std;

void permutationsHelper(vector<vector<int>>& permutations, vector<int>& array, int idx) {
    if (idx == array.size() - 1) {
        permutations.push_back(array);
    } else {
        for (int j = idx; j < array.size(); j++) {
            swap(array[idx], array[j]);
            permutationsHelper(permutations, array, idx + 1);
            swap(array[idx], array[j]);
        }
    }
    return;
}

vector<vector<int>> getPermutations(vector<int> array) {
    vector<vector<int>> permutations;
    permutationsHelper(permutations, array, 0);
    return permutations;
}
