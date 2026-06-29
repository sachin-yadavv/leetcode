class MyCalendarTwo {
public:
    vector<pair<int,int>> calendar;
    vector<pair<int,int>> overlaps;

    MyCalendarTwo() {

    }

    bool book(int start, int end) {

        // Check for triple booking
        for (auto &p : overlaps) {
            if (start < p.second && end > p.first)
                return false;
        }

        // Create new double-booked intervals
        for (auto &p : calendar) {

            if (start < p.second && end > p.first) {

                overlaps.push_back({
                    max(start, p.first),
                    min(end, p.second)
                });

            }
        }

        calendar.push_back({start,end});

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */