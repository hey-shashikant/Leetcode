class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int>uMap;
        for (int i = 0; i < nums.size(); i++) {
            int element = target - nums[i];
            if (uMap.find(element) != uMap.end()) {
                return {uMap[element], i};
            }
            uMap[nums[i]] = i;
        }
        return {-1,-1};
    }
};