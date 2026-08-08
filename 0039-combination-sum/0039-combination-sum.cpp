class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int i, vector<int>& candidates, int target) {

        // Target achieved
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // No candidates left or target became invalid
        if (i == candidates.size() || target < 0) {
            return;
        }

        // ---------------- TAKE ----------------
        temp.push_back(candidates[i]);

        // i stays same because we can reuse candidates[i]
        if(target>0)
        solve(i, candidates, target - candidates[i]);

        temp.pop_back();


        // ---------------- SKIP ----------------
        solve(i + 1, candidates, target);
    }

    vector<vector<int>> combinationSum(
        vector<int>& candidates,
        int target
    ) {
        solve(0, candidates, target);
        return ans;
    }
};