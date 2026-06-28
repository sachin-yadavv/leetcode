class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merged;

        for (auto &x : occupiedIntervals) {
            if (merged.empty() || x[0] > merged.back()[1] + 1) {
                merged.push_back(x);
            } else {
                merged.back()[1] = max(merged.back()[1], x[1]);
            }
        }

        vector<vector<int>> ans;

        for (auto &x : merged) {
            int l = x[0], r = x[1];

            // No overlap
            if (r < freeStart || l > freeEnd) {
                ans.push_back({l, r});
                continue;
            }

            // Left part remains
            if (l < freeStart)
                ans.push_back({l, freeStart - 1});

            // Right part remains
            if (r > freeEnd)
                ans.push_back({freeEnd + 1, r});
        }

        return ans;
    }
};