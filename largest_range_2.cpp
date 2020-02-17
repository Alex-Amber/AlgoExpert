#include <bits/stdc++.h>

using namespace std;

vector<int> largestRange(vector<int> array) {
    unordered_map<int, bool> nums;
    for (int num : array) {
        nums[num] = false;
    }
    int longest_length = 0, longest_start = 0, longest_end = 0;
    for (int num : array) {
        if (!nums[num]) {
            nums[num] = true;
            int start = num, end = num;
            while (nums.count(start - 1)) {
                nums[--start] = true;
            }
            while (nums.count(end + 1)) {
                nums[++end] = true;
            }
            if (end - start + 1 > longest_length) {
                longest_length = end - start + 1;
                longest_start = start;
                longest_end = end;
            }
        }
    }
    return {longest_start, longest_end};
}
