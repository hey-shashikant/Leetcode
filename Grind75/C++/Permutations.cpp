class Solution {
public:
    bool contains(const std::vector<int>& vec, int target) {
        for (auto i : vec) {
            if (i == target) {
                return true;
            }
        }
        return false;
    }

    void helper(std::vector<std::vector<int>>& result, std::vector<int>& temp, const std::vector<int>& nums) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (contains(temp, nums[i])) {
                continue;
            }

            temp.push_back(nums[i]);
            helper(result, temp, nums);
            temp.pop_back();
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> temp;
        helper(result, temp, nums);
        return result;
    }
};
