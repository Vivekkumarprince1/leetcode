class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        long long result = 0;

        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            long long value = result * sign;
            if (value <= INT_MIN) return INT_MIN;
            if (value >= INT_MAX) return INT_MAX;

            i++;
        }

        return static_cast<int>(result * sign);
    }
};