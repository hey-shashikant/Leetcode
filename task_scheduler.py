class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        uMap = {}
        freq, X = 0,0
        for task in tasks:
            uMap[task] = uMap.get(task,0) + 1

            freq = max(freq,uMap[task])
        
        for value in uMap.values():
            if value == freq:
                X += 1
        
        return max((freq-1)*(n+1) + X, len(tasks))