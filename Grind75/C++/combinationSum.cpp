class Solution {
public:
    void helper(int idx, const std::vector<int>& candidates, int target, std::vector<int>& temp, std::vector<std::vector<int>>& result) {
        if (idx == candidates.size()) {
            if (target == 0) {
                result.push_back(temp);
            }
            return;
        }

        if (candidates[idx] <= target) {
            temp.push_back(candidates[idx]);
            helper(idx, candidates, target - candidates[idx], temp, result);
            temp.pop_back();
        }

        helper(idx + 1, candidates, target, temp, result);
    }

    std::vector<std::vector<int>> combinationSum(const std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result; 
        std::vector<int> temp;
        helper(0, candidates, target, temp, result);
        return result;
    }
};