class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        int maxFreq = 0;
        int ans = 0;

        for (auto it : mp) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                ans = it.first;
            }
        }

        return ans;
    }
};