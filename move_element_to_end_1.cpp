#include <bits/stdc++.h>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
    int n = array.size();
    int left = 0, right = n - 1;
    while (left < right) {
        while (right >= 0 && array[right] == toMove) {
            right--;
        }
        while (left < n && array[left] != toMove) {
            left++;
        }
        if (right >= 0 && left < n && left < right) {
            swap(array[left], array[right]);
            left++;
            right--;
        }
    }
    return array;
}
