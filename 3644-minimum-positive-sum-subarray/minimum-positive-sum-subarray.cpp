class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

        int ans = INT_MAX;
        for (int start = 0; start < n; start++) {
            for (int len = l; len <= r && start + len <= n; len++) {
                int s = pre[start + len] - pre[start];
                if (s > 0 && s < ans) ans = s;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};