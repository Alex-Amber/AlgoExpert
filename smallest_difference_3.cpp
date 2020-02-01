#include <bits/stdc++.h>

using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());
    int smallest_diff = INT_MAX;
    int current_diff = INT_MAX;
    vector<int> smallest_pair;
    int ptr_one = 0, ptr_two = 0;
    while (ptr_one < arrayOne.size() && ptr_two < arrayTwo.size()) {
        int first_num = arrayOne[ptr_one];
        int second_num = arrayTwo[ptr_two];
        if (first_num < second_num) {
            current_diff = abs(first_num - second_num);
            ptr_one++;
        }
        else if (first_num > second_num) {
            current_diff = abs(first_num - second_num);
            ptr_two++;
        }
        else {
            smallest_pair = {first_num, second_num};
            break;
        }
        if (current_diff < smallest_diff) {
            smallest_diff = current_diff;
            smallest_pair = {first_num, second_num};
        }
    }
    return smallest_pair;
}
