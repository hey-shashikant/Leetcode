class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 1, ele = nums[0];
        for(int i : nums) {
            if (i == ele) {
                freq += 1;
            } else {
                freq -= 1;
                if (freq == 0) {
                    freq = 1;
                    ele = i;
                }
            }
        }
        return ele;
    }
};