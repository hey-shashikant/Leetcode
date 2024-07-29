class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        result = []
        intervals.sort()
        begin,end = intervals[0][0], intervals[0][1]

        for i in range(1,len(intervals)):
            if intervals[i][0] <= end:
                end = max(end, intervals[i][1])
            else:
                result.append([begin,end])
                begin = intervals[i][0]
                end = intervals[i][1]

        result.append([begin,end])
        return result