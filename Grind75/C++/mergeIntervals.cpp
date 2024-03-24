class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) // Check if intervals vector is empty
            return {};

        // Sort intervals based on the start time
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> mergedIntervals;
        int start = intervals[0][0], end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            // Check for overlapping intervals
            if (end >= intervals[i][0]) {
                end = max(end, intervals[i][1]);
            } else {
                mergedIntervals.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        // Add the last merged interval
        mergedIntervals.push_back({start, end});

        return mergedIntervals;
    }
};