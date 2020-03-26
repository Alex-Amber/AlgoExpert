#include <bits/stdc++.h>

using namespace std;

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
    if (arrayOne.empty() && arrayTwo.empty()) {
        return true;
    }
    if (arrayOne.empty() || arrayTwo.empty()) {
        return false;
    }
    if (arrayOne.size() != arrayTwo.size()) {
        return false;
    }
    int rootOne = arrayOne[0], rootTwo = arrayTwo[0];
    vector<int> leftSubarrayOne, rightSubarrayOne, leftSubarrayTwo, rightSubarrayTwo;
    for (int i = 1; i < arrayOne.size(); i++) {
        if (arrayOne[i] < rootOne) {
            leftSubarrayOne.push_back(arrayOne[i]);
        } else {
            rightSubarrayOne.push_back(arrayOne[i]);
        }
    }
    for (int i = 1; i < arrayTwo.size(); i++) {
        if (arrayTwo[i] < rootTwo) {
            leftSubarrayTwo.push_back(arrayTwo[i]);
        } else {
            rightSubarrayTwo.push_back(arrayTwo[i]);
        }
    }
    return rootOne == rootTwo && sameBsts(leftSubarrayOne, leftSubarrayTwo) && sameBsts(rightSubarrayOne, rightSubarrayTwo);
}