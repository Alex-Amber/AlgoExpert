#include <bits/stdc++.h>

using namespace std;

bool balancedBrackets(string str) {
    stack<char> stk;
    for (char ch : str) {
        if (ch == ')') {
            if (!stk.empty() && stk.top() == '(') {
                stk.pop();
            } else {
                return false;
            }
        } else if (ch == ']') {
            if (!stk.empty() && stk.top() == '[') {
                stk.pop();
            } else {
                return false;
            }
        } else if (ch == '}') {
            if (!stk.empty() && stk.top() == '{') {
                stk.pop();
            } else {
                return false;
            }
        } else {
            stk.push(ch);
        }
    }
    return stk.empty();
}
