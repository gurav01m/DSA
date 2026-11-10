class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int j = 1; j <= n; j++) {
            for (int d = 1; d <= 3 && j - d >= 0; d++) {
                if (dp[j - d] == INT_MAX) continue;
                dp[j] = min(dp[j], dp[j - d] + costs[j - 1] + d * d);
            }
        }
        return dp[n];
    }
};