class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<long long>> left(m, vector<long long>(n, 0));
        vector<vector<long long>> up(m, vector<long long>(n, 0));

        left[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long L = left[i][j];
                long long U = up[i][j];

                if (grid[i][j] == 1) {
                    // Entering from left: reflect down
                    if (i + 1 < m)
                        up[i + 1][j] = (up[i + 1][j] + L) % MOD;

                    // Entering from above: reflect right
                    if (j + 1 < n)
                        left[i][j + 1] = (left[i][j + 1] + U) % MOD;
                } 
                else {
                    // Normal cell: can move right or down
                    long long ways = (L + U) % MOD;

                    if (j + 1 < n)
                        left[i][j + 1] =
                            (left[i][j + 1] + ways) % MOD;

                    if (i + 1 < m)
                        up[i + 1][j] =
                            (up[i + 1][j] + ways) % MOD;
                }
            }
        }

        return (left[m - 1][n - 1] + up[m - 1][n - 1]) % MOD;
    }
};