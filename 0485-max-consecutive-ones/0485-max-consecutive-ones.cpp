class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0;
        int cnt = 0;
        int i = 0;

        while (i < nums.size()) {
            if (nums[i] == 1) {
                cnt++;
            } else {
                mx = max(mx, cnt);
                cnt = 0;
            }
            i++;
        }

        mx = max(mx, cnt);

        return mx;
    }
};