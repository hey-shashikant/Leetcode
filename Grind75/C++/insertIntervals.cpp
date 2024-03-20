class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0, size = intervals.size();
        // case 1: where there is no overlapping intervals.
        while (i < size and intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        // case 2: where there is no overlapping intervals.
        while (i < size and newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        } 
        ans.push_back(newInterval);
        // case 3: no overlapping intervals.
        while(i < size) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};