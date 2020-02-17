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

struct OrgChartInfo {
    OrgChart *topManager;
    int numCoveredReports;
};

OrgChartInfo getOrgChartInfo(OrgChart *topManager, OrgChart *reportOne, OrgChart *reportTwo) {
    int num_covered_reports = 0;
    for (auto child : topManager->directReports) {
        OrgChartInfo res = getOrgChartInfo(child, reportOne, reportTwo);
        if (res.topManager) {
            return res;
        }
        num_covered_reports += res.numCoveredReports;
    }
    if (topManager == reportOne || topManager == reportTwo) {
        num_covered_reports++;
    }
    OrgChartInfo res;
    res.topManager = num_covered_reports == 2 ? topManager : NULL;
    res.numCoveredReports = num_covered_reports;
    return res;
}

OrgChart *getLowestCommonManager(OrgChart *topManager, OrgChart *reportOne,
                                 OrgChart *reportTwo) {
    return getOrgChartInfo(topManager, reportOne, reportTwo).topManager;
}
