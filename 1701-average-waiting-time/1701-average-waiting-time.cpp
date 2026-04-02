class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double sum = 0;      // current time
        double waiting = 0;
        int n = customers.size();

        for (auto it : customers) {
            int arrival = it[0];
            int time = it[1];

            if (sum < arrival) {
                sum = arrival;   // chef waits
            }

            sum += time;         // cooking
            waiting += (sum - arrival);
        }

        return waiting / n;
    }
};