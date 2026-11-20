class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(1000003, 0);
        int ans = 1;
        for (int x : nums) {
            dp[x + 1] = dp[x] + 1;      // x ko x+1 bana diya
            dp[x] = dp[x - 1] + 1;      // x ko x hi rakha
            ans = max(ans, max(dp[x], dp[x + 1]));
        }
        return ans;
    }
};