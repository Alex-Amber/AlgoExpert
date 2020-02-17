#include <bits/stdc++.h>

using namespace std;

struct StringMeeting {
    string start;
    string end;
};

struct IntMeeting {
    int start;
    int end;
};

string intToStringTime(int minutes) {
    int hours = minutes / 60;
    minutes = minutes % 60;
    string res = to_string(hours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes);
    return res;
}

int stringToIntTime(string time) {
    int delim_pos = time.find(':');
    int hours = stoi(time.substr(0, delim_pos));
    int minutes = stoi(time.substr(delim_pos + 1));
    return hours * 60 + minutes;
}

StringMeeting intToStringMeeting(IntMeeting m) {
    StringMeeting res;
    res.start = intToStringTime(m.start);
    res.end = intToStringTime(m.end);
    return res;
}

IntMeeting stringToIntMeeting(StringMeeting m) {
    IntMeeting res;
    res.start = stringToIntTime(m.start);
    res.end = stringToIntTime(m.end);
    return res;
}

bool meetingOverlapped(IntMeeting m1, IntMeeting m2) {
    return m1.start > m2.end && m2.start > m1.end;
}

IntMeeting unionMeeting(IntMeeting m1, IntMeeting m2) {
    IntMeeting res;
    res.start = min(m1.start, m2.start);
    res.end = max(m1.end, m2.end);
    return res;
}

IntMeeting intersectionMeeting(IntMeeting m1, IntMeeting m2) {
    IntMeeting res;
    res.start = max(m1.start, m2.start);
    res.end = min(m1.end, m2.end);
    return res;
}

bool compareIntMeeting(IntMeeting a, IntMeeting b) {
    return a.start < b.start;
}

vector<StringMeeting> calendarMatching(vector<StringMeeting> calendar1,
                                       StringMeeting dailyBounds1,
                                       vector<StringMeeting> calendar2,
                                       StringMeeting dailyBounds2,
                                       int meetingDuration) {
    IntMeeting union_daily_bounds = intersectionMeeting(stringToIntMeeting(dailyBounds1), stringToIntMeeting(dailyBounds2));
    vector<IntMeeting> union_calendar, int_calendar1, int_calendar2;
    int m = calendar1.size(), n = calendar2.size();
    for (int i = 0; i < m; i++) {
        union_calendar.push_back(stringToIntMeeting(calendar1[i]));
    }
    for (int i = 0; i < n; i++) {
        union_calendar.push_back(stringToIntMeeting(calendar2[i]));
    }
    sort(union_calendar.begin(), union_calendar.end(), compareIntMeeting);
    int cur = 0, next = 1;
    while (cur < union_calendar.size() && next < union_calendar.size()) {
        if (meetingOverlapped(union_calendar[cur], union_calendar[next])) {
            union_calendar[cur] = unionMeeting(union_calendar[cur], union_calendar[next]);
            union_calendar[next].start = -1;
            union_calendar[next].end = -1;
            next++;
        }
        else {
            cur = next;
            next = cur + 1;
        }
    }
    vector<StringMeeting> res;
    int left = union_daily_bounds.start, right = 0;
    for (int i = 0; i < union_calendar.size(); i++) {
        if (union_calendar[i].start != -1 || union_calendar[i].end != -1) {
            right = union_calendar[i].start;
            if (right > union_daily_bounds.end) {
                break;
            }
            if (right <= left) {
                left = max(left, union_calendar[i].end);
                continue;
            }
            if (right - left >= meetingDuration) {
                StringMeeting m;
                m.start = intToStringTime(left);
                m.end = intToStringTime(right);
                res.push_back(m);
            }
            left = union_calendar[i].end;
        }
    }
    right = union_daily_bounds.end;
    if (right - left >= meetingDuration) {
        StringMeeting m;
        m.start = intToStringTime(left);
        m.end = intToStringTime(right);
        res.push_back(m);
    }
    return res;
}
