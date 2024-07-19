class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int begin = 0, end = nums.size()-1;
        while(begin < end) {
            int value = nums[begin] + nums[end];
            if (value == target) {
                return {begin + 1, end + 1};
            } else if (value < target) {
                begin += 1;
            } else {
                end -= 1;
            }
        }
        return {-1, -1};
    }
};