class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pas;
        for (int i=0; i<numRows;i++){
            vector<int> row (i+1,1);
            for (int j=1; j<i; j++){
                row[j]=pas[i-1][j-1]+pas[i-1][j];
            }
            pas.push_back(row);

        }
        return pas;
    }
};