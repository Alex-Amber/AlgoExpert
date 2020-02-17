#include <bits/stdc++.h>

using namespace std;

class MinMaxStack {
public:
    int peek() {
        if (stk.empty()) {
            return -1;
        } else {
            return stk.back();
        }
    }

    int pop() {
        if (stk.empty()) {
            return -1;
        }
        int res = stk.back();
        stk.pop_back();
        min_stk.pop_back();
        max_stk.pop_back();
        return res;
    }

    void push(int number) {
        if (!stk.empty()) {
            min_stk.push_back(min(number, getMin()));
            max_stk.push_back(max(number, getMax()));
        } else {
            min_stk.push_back(number);
            max_stk.push_back(number);
        }
        stk.push_back(number);
    }

    int getMin() {
        if (stk.empty()) {
            return -1;
        } else {
            return min_stk.back();
        }
    }

    int getMax() {
        if (stk.empty()) {
            return -1;
        } else {
            return max_stk.back();
        }
    }
private:
    vector<int> stk;
    vector<int> min_stk;
    vector<int> max_stk;
};
