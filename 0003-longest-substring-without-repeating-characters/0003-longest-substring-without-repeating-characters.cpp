class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;

        int l = 0, r = 0;
        int maxlen = 0;
        int n = s.size();

        while (r < n) {
            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;
            }

            int len = r - l + 1;
            maxlen = max(maxlen, len);

            mp[s[r]] = r;
            r++;
        }

        return maxlen;
    }
};