class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        vector<vector<int>> p = m;

        int n = m.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = p[n - 1 - j][i];
            }
        }
    }
};