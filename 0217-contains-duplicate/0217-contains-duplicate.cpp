// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_set<int>mp;
//         for(int num:nums){
//             if(mp.count(num))return true;
//             mp.insert(num);
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp[nums[i]] > 0) {
                return true;
            }
            mp[nums[i]]++;
        }
        return false;
    }
};