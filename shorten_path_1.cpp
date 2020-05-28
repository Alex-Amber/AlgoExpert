#include <bits/stdc++.h>

using namespace std;

string shortenPath(string path) {
    path.push_back('/');
    vector<string> stk;
    if (path[0] == '/') {
        stk.push_back("/"); 
    }
    int start = 0, end = 0;
    while (path[start] == '/') {
        start++;
    }
    while ((end = path.find('/', start)) != string::npos) {
        string component = path.substr(start, end - start);
        if (component == "..") {
            if (stk.empty() || stk.back() == "..") {
                stk.push_back(component);
            } else if (stk.back() == "/") {
                ;
            } else {
                stk.pop_back();
            }
        } else if (component == ".") {
            ;
        } else {
            stk.push_back(component);
        }
        start = end + 1;
        while (path[start] == '/') {
            start++;
        }
    }
    string result;
    for (int i = 0; i < stk.size() - 1; i++) {
        result += (stk[i] == "/" ? "" : stk[i]) + "/";
    }
    result += stk.back();
    path.pop_back();
    return result;
}
