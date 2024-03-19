class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int begin = i + 1, end = nums.size() - 1;
            while(begin < end) {
                int sum = nums[i] + nums[begin] + nums[end];
                if (sum == 0) {
                    vector<int> tmp = {nums[i],nums[begin],nums[end]};
                    result.push_back(tmp);
                    while (begin <= end and nums[begin] == tmp[1]) {
                        begin += 1;
                    }
                    while (end >= 0 and nums[end] == tmp[2]) {
                        end -= 1;
                    }
                } else if (sum > 0) {
                    end -= 1;
                } else {
                    begin += 1;
                }
            }
            while (i+1 < nums.size() and nums[i] == nums[i+1]) {
                i += 1;
            }
        }
        return result;
    }
};