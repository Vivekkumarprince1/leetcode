class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0;
        int odd = 0;
        int count = 0;
        int ans = 0;

        for (int j = 0; j < nums.size(); j++) {

            if (nums[j] % 2 == 1) {
                odd++;
                count = 0;          // reset when a new odd enters
            }

            while (odd == k) {
                count++;

                if (nums[i] % 2 == 1)
                    odd--;

                i++;
            }

            ans += count;
        }

        return ans;
    }
};