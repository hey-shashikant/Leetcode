class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pQueue = new PriorityQueue<Integer>();
        for(int i = 0; i < nums.length; i += 1) {
            pQueue.add(nums[i]);
            if(pQueue.size() > k)
                pQueue.poll();
        }
        return pQueue.peek();
    }
}