class Solution {
    public int lengthOfLongestSubstring(String s) {
        int cnt = 0;
        for(int i = 0; i < s.length(); i += 1) {
            int[] freq = new int[128];
            Arrays.fill(freq,-1);
            for(int j = i; j < s.length(); j += 1) {
                if(freq[(int)s.charAt(j)] != -1) {
                    break;
                } else {
                    freq[(int)s.charAt(j)] = 1;
                    cnt = Math.max((j-i)+1,cnt);
                }
            }
        }
        return cnt;
    }
}