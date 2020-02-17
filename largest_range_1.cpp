#include <bits/stdc++.h>

using namespace std;

vector<int> largestRange(vector<int> array) {
    sort(array.begin(), array.end());
    int longest_length = 0, longest_start = -1, longest_end = -1;
    int start = array[0], end = array[0];
    for (int i = 1; i < array.size(); i++) {
         
        if (array[i] - end <= 1) {
            end = array[i];
        }
        else {
            int last_length = end - start + 1;
            if (last_length > longest_length) {
                longest_length = last_length;
                longest_start = start;
                longest_end = end;
            }
            start = array[i];
            end = array[i];
        }
    }
    int last_length = end - start + 1;
    if (last_length > longest_length) {
        longest_length = last_length;
        longest_start = start;
        longest_end = end;
    }
    return {longest_start, longest_end};
}
