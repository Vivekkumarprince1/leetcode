class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int i, vector<int>& candidates, int target) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (i == candidates.size() || target < 0) {
            return;
        }

        // TAKE
        temp.push_back(candidates[i]);

        // i + 1 => don't reuse the same candidate
        solve(i + 1, candidates, target - candidates[i]);

        temp.pop_back();


        // SKIP all duplicates of candidates[i]
        int j = i + 1;

        while (j < candidates.size() &&
               candidates[j] == candidates[i]) {
            j++;
        }

        solve(j, candidates, target);
    }

    vector<vector<int>> combinationSum2(
        vector<int>& candidates,
        int target
    ) {
        sort(candidates.begin(), candidates.end());

        solve(0, candidates, target);

        return ans;
    }
};