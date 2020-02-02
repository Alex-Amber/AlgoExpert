#include <bits/stdc++.h>

using namespace std;

vector<int> subarraySort(vector<int> array) {
    vector<int> sorted_array = array;
    sort(sorted_array.begin(), sorted_array.end());
    int n = array.size();
    int left = 0, right = n - 1;
    while (left < n && sorted_array[left] == array[left]) {
        left++;
    }
    while (right >= 0 && sorted_array[right] == array[right]) {
        right--;
    }
    if (left < n) {
        return {left, right};
    }
    else {
        return {-1, -1};
    }
}
