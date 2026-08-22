class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> arr;
        int cur=0;
        int n=nums.size();
        int max_sum=INT_MIN;
        for(int i=0;i<n;i++){
            cur+=nums[i];
            max_sum=max(max_sum,cur);
            if(cur<0)cur=0;
        }

return max_sum;
    }
};