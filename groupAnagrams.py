class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = []
        uMap = defaultdict(list)
        for s in strs:
            temp = ''.join(sorted(s))
            uMap[temp].append(s)
        
        for value in uMap.values():
            res.append(value)
        
        return res
            