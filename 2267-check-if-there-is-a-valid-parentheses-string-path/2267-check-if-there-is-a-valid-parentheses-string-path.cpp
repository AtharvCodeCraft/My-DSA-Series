#include <vector>

using namespace std;

class Solution {
    int m, n;
    // dp[r][c][bal] tracks whether a valid path exists starting from (r, c) with current balance `bal`
    int memo[100][100][105];

    bool solve(int r, int c, int bal, vector<vector<char>>& grid) {
        // Update balance for current cell
        bal += (grid[r][c] == '(' ? 1 : -1);

        // If balance goes negative, this path is invalid
        if (bal < 0) return false;

        // Base case: reached bottom-right cell
        if (r == m - 1 && c == n - 1) {
            return bal == 0;
        }

        // Return cached result if already computed
        if (memo[r][c][bal] != -1) {
            return memo[r][c][bal];
        }

        bool possible = false;

        // Move Down
        if (r + 1 < m) {
            possible = possible || solve(r + 1, c, bal, grid);
        }

        // Move Right
        if (!possible && c + 1 < n) {
            possible = possible || solve(r, c + 1, bal, grid);
        }

        return memo[r][c][bal] = possible;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Quick check: total length must be even, starting cell must be '(', ending cell must be ')'
        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        // Initialize memo table with -1
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k <= (m + n) / 2; ++k) {
                    memo[i][j][k] = -1;
                }
            }
        }

        return solve(0, 0, 0, grid);
    }
};