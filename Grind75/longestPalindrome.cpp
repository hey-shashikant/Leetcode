class Solution {
public:
    int longestPalindrome(string s) {
        int length = 0;
        bool check = false;
        unordered_map<char,int>frequency;
        for (char ch : s) {
            frequency[ch] ++;
        }
        for (const auto& it : frequency) {
            if (it.second % 2 == 0) {
                length += it.second;
            } else {
                length += it.second - 1;
                check = true;
            }
        }
        return check ? length + 1 : length;
    }
};