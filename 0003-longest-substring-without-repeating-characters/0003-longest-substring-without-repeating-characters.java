class Solution {
    public int lengthOfLongestSubstring(String s) {
        int i = 0, j = 0, cnt = 0;
        int[] freq = new int[128];
        Arrays.fill(freq,-1);
        while(i < s.length()) {
            if(freq[(int)s.charAt(i)] != -1) {
                while(freq[(int)s.charAt(i)] != -1) {
                    freq[(int)s.charAt(j)] = -1;
                    j += 1;
                }
            } else {
                freq[s.charAt(i)] = 1;
                i += 1;
            }
            cnt = Math.max(cnt,(i-j));
        }
        return cnt;
    }
}