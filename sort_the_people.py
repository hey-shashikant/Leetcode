from typing import List

class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        n = len(names)
        map = {heights[i] : names[i] for i in range(n)}
        heights.sort(reverse=True)
        for i in range(n):
            names[i] = map[heights[i]]
        return names
    
solution = Solution()
names = list(input().split())
heights = list(map(int,input().split()))
sortedPeople = solution.sortPeople(names,heights)
print(sortedPeople)