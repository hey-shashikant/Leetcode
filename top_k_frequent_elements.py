from typing import List
import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        uMap = {}
        result = []
        for num in nums:
            uMap[num] = uMap.get(num,0) + 1
        
        pq = []
        for num, freq in uMap.items():
            heapq.heappush(pq,(freq,num))
            if len(pq) > k:
                heapq.heappop(pq)
                
        while pq:
            freq,num = heapq.heappop(pq)
            result.append(num)
        
        return result
        