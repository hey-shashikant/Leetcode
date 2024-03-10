class Solution {
public:
    string addBinary(string a, string b) {
        std::string result = "";
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            result += '0' + sum % 2;
            carry = sum / 2;
        }

        if (carry) result += '1';

        std::reverse(result.begin(), result.end());
        return result;
    }
};