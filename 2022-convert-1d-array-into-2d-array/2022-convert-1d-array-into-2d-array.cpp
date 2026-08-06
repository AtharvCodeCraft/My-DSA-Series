class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    vector<vector<int>> result(m, vector<int>(n));

    if(original.size() != m*n) {
        return {};
    }
    int idx = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            result[i][j] = original[idx];
            idx++;

        }
    }
    return result;
    }
};

/*
2nd approach

for (int i = 0; i < original.size(); i++) {
int row = i / n;
int col = i % n;

result[row][col] = original[i];
}
return result;
*/