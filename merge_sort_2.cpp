#include <bits/stdc++.h>

using namespace std;

void mergeSubarrays(vector<int>& main_array, vector<int>& aux_array, 
                    int left_start_idx, int left_end_idx,
                    int right_start_idx, int right_end_idx) {
    int main_idx = left_start_idx;
    int i = left_start_idx, j = right_start_idx;
    while (i <= left_end_idx && j <= right_end_idx) {
        if (aux_array[i] < aux_array[j]) {
            main_array[main_idx++] = aux_array[i++];
        } else {
            main_array[main_idx++] = aux_array[j++];
        }
    }
    while (i <= left_end_idx) {
        main_array[main_idx++] = aux_array[i++];
    }
    while (j <= right_end_idx) {
        main_array[main_idx++] = aux_array[j++];
    }
    return;
}

void mergeSortHelper(vector<int>& main_array, vector<int>& aux_array, int start_idx, int end_idx) {
    if (start_idx >= end_idx) {
        return;
    }
    int mid = (start_idx + end_idx) / 2;
    mergeSortHelper(aux_array, main_array, start_idx, mid);
    mergeSortHelper(aux_array, main_array, mid + 1, end_idx);
    mergeSubarrays(main_array, aux_array, start_idx, mid, mid + 1, end_idx);
    return;
}

vector<int> mergeSort(vector<int> array) {
    vector<int> aux(array);
    mergeSortHelper(array, aux, 0, array.size() - 1);
    return array;
}
