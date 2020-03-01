#include <bits/stdc++.h>

using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
    int firstLargest = INT_MIN, secondLargest = INT_MIN, thirdLargest = INT_MIN;
    for (int num: array) {
        if (num > thirdLargest) {
            thirdLargest = num;
            if (num > secondLargest) {
                swap(secondLargest, thirdLargest);
                if (num > firstLargest) {
                    swap(firstLargest, secondLargest);
                }
            }
        }
    }
    return vector<int>({thirdLargest, secondLargest, firstLargest});
}
