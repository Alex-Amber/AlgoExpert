#include <bits/stdc++.h>

using namespace std;

class OrgChart {
public:
    char name;
    vector<OrgChart *> directReports;

    OrgChart(char name) {
        this->name = name;
        this->directReports = {};
    }

    void addDirectReports(vector<OrgChart *> directReports);
};

OrgChart *postOrderTraverse(unordered_set<OrgChart *>& managers, OrgChart *topManager,
                            OrgChart *reportOne, OrgChart *reportTwo) {
    OrgChart *res = NULL;
    for (auto child : topManager->directReports) {
        unordered_set<OrgChart *> sub_managers;
        res = postOrderTraverse(sub_managers, child, reportOne, reportTwo);
        if (res) {
            return res;
        }
        managers.insert(sub_managers.begin(), sub_managers.end());
    }
    managers.insert(topManager);
    if (managers.count(reportOne) && managers.count(reportTwo)) {
        return topManager;
    }
    return NULL;
}

OrgChart *getLowestCommonManager(OrgChart *topManager, OrgChart *reportOne,
                                 OrgChart *reportTwo) {
    unordered_set<OrgChart *> managers;
    return postOrderTraverse(managers, topManager, reportOne, reportTwo);
}
