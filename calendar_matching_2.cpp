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

int timeToMinutes(string time) {
    int delim_pos = time.find(':');
    int hours = stoi(time.substr(0, delim_pos));
    int minutes = stoi(time.substr(delim_pos + 1));
    return hours * 60 + minutes;
}

string minutesToTime(int minutes) {
    int hours = minutes / 60;
    minutes = minutes % 60;
    string res = to_string(hours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes);
    return res;
}

vector<IntMeeting> updateCalendar(vector<StringMeeting> calendar, StringMeeting dailyBounds) {
    vector<IntMeeting> res;
    res.push_back({0, timeToMinutes(dailyBounds.start)});
    for (int i = 0; i < calendar.size(); i++) {
        res.push_back({timeToMinutes(calendar[i].start),
                       timeToMinutes(calendar[i].end)});
    }
    res.push_back({timeToMinutes(dailyBounds.end), 24 * 60});
    return res;
}

vector<IntMeeting> mergeCalendars(vector<IntMeeting> calendar1, vector<IntMeeting> calendar2) {
    vector<IntMeeting> res;
    int i = 0, j = 0;
    while (i < calendar1.size() && j < calendar2.size()) {
        if (calendar1[i].start < calendar2[j].start) {
            res.push_back(calendar1[i++]);
        }
        else {
            res.push_back(calendar2[j++]);
        }
    }
    while (i < calendar1.size()) {
        res.push_back(calendar1[i++]);
    }
    while (j < calendar2.size()) {
        res.push_back(calendar2[j++]);
    }
    return res;
}

vector<IntMeeting> flattenCalendar(vector<IntMeeting> calendar) {
    vector<IntMeeting> res = {calendar[0]};
    for (int i = 1; i < calendar.size(); i++) {
        if (calendar[i].start <= res.back().end) {
            res.back().end = max(calendar[i].end, res.back().end);
        }
        else {
            res.push_back(calendar[i]);
        }
    }
    return res;
}

vector<StringMeeting> calendarMatching(vector<StringMeeting> calendar1,
                                       StringMeeting dailyBounds1,
                                       vector<StringMeeting> calendar2,
                                       StringMeeting dailyBounds2,
                                       int meetingDuration) {
    vector<IntMeeting> updated_calendar1 = updateCalendar(calendar1, dailyBounds1);
    vector<IntMeeting> updated_calendar2 = updateCalendar(calendar2, dailyBounds2);
    vector<IntMeeting> merged_calendar = mergeCalendars(updated_calendar1, updated_calendar2);
    vector<IntMeeting> flattened_calendar = flattenCalendar(merged_calendar);
    vector<IntMeeting> availabilities;
    int start = 0, end = 0;
    for (int i = 0; i < flattened_calendar.size() - 1; i++) {
        start = flattened_calendar[i].end;
        end = flattened_calendar[i + 1].start;
        if (end - start >= meetingDuration) {
            availabilities.push_back({start, end});
        }
    }
    vector<StringMeeting> res;
    for (auto meeting : availabilities) {
        res.push_back({minutesToTime(meeting.start),
                       minutesToTime(meeting.end)});
    }
    return res;
}
