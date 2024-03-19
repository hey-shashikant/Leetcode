class Solution {
public:
    bool isPalindrome(string s) {
        int begin = 0, end = s.length() - 1;
        while (begin <= end) {
            while(begin <= end and std::isalnum(s[begin]) == false) {
                begin += 1;
            }
            while( end >= 0 and std::isalnum(s[end]) == false) {
                end -= 1;
            }
            if (begin <= end and std::tolower(s[begin]) != std::tolower(s[end])) {
                return false;
            } 
            begin += 1;
            end -= 1;
        }
        return true;
    }
};