#include <bits/stdc++.h>
using namespace std;

// Definition of Interval:
class Interval {
   public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
   public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() == 0) return true;

        sort(intervals.begin(), intervals.end(),
             [](Interval a, Interval b) { return a.start < b.start; });

        Interval prev = intervals[0];
        int n = intervals.size();

        for (int i = 1; i < n; ++i) {
            if (prev.end > intervals[i].start) {
                return false;
            }
            prev = intervals[i];
        }

        return true;
    }
};
