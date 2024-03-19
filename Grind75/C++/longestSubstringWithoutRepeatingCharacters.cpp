class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int frequency[128] = {0};
        int i = 0, j = 0, maxLen = 0;
        while (j < s.length()) {
            if (frequency[int(s[j])] == 0) {
                frequency[int(s[j])] = 1;
                j++;
            } else {
                while (frequency[int(s[j])] != 0) {
                    frequency[int(s[i])] = 0;
                    i++;
                }
            }
            maxLen = max(maxLen,(j - i));
        }
        return maxLen;
    }
};