class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int index, vector<int> arr, int fact) {
        
        if (temp.size() == arr.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (find(temp.begin(), temp.end(), arr[i]) != temp.end())
                continue;

            temp.push_back(arr[i]);
            solve(index + 1, arr, fact);
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int fact = 1;
        for (int i = 1; i <= nums.size(); i++) {
            fact = fact * i;
        }

        solve(0, nums, fact);
        return ans;
    }
};