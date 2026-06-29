class MyCalendar {
public:
    vector<pair<int,int>> calendar;

    MyCalendar() {
    }

    bool book(int startTime, int endTime) {

        for (auto &event : calendar) {
            int s = event.first;
            int e = event.second;

            if (startTime < e && endTime > s)
                return false;
        }

        calendar.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */