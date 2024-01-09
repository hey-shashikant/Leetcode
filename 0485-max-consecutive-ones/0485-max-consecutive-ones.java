class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int cnt = 0, i = 0, maxCount = 0;
        while(i < nums.length) {
            if(nums[i] == 1) {
                cnt += 1;
            } else {
                cnt = 0;
            }
            i += 1;
            maxCount = Math.max(cnt,maxCount);
        }
        return maxCount;
    }
}