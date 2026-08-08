class Solution {
public:
vector<int>ans;
vector<vector<int>> k;
    void solve(int index, vector<int> nums){
        k.push_back(ans);

        for ( int i=index; i<nums.size();i++){
            if(i>index &&nums[i-1]==nums[i])
            continue;
            ans.push_back(nums[i]);
            solve(i + 1, nums);
            ans.pop_back();
        }
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(0,nums);   
        return k;
    }
};