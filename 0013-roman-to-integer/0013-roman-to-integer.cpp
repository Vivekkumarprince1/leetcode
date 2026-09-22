class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            int curr;
            int next = 0;

            if (s[i] == 'M') curr = 1000;
            else if (s[i] == 'D') curr = 500;
            else if (s[i] == 'C') curr = 100;
            else if (s[i] == 'L') curr = 50;
            else if (s[i] == 'X') curr = 10;
            else if (s[i] == 'V') curr = 5;
            else curr = 1;

            if (i + 1 < s.size()) {
                if (s[i + 1] == 'M') next = 1000;
                else if (s[i + 1] == 'D') next = 500;
                else if (s[i + 1] == 'C') next = 100;
                else if (s[i + 1] == 'L') next = 50;
                else if (s[i + 1] == 'X') next = 10;
                else if (s[i + 1] == 'V') next = 5;
                else next = 1;
            }

            if (curr < next)
                ans -= curr;
            else
                ans += curr;
        }

        return ans;
    }
};