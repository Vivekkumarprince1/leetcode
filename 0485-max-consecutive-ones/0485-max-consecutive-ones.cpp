class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, mx = 0;
        for (int x : nums) {
            if (x == 1)
                cnt++;
            else
                cnt = 0;

            mx = max(mx, cnt);
        }

        return mx;
    }
};