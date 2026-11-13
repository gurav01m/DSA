class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;          // prefix-max records, front = leftmost
        long long cost = 0, ans = 0;
        int R = n - 1;

        for (int l = n - 1; l >= 0; l--) {
            long long v = nums[l];

            // records with value <= v merge into the new segment of l
            while (!dq.empty() && nums[dq.front()] <= v) {
                int j = dq.front();
                int end = (dq.size() > 1) ? dq[1] - 1 : R;
                cost += (v - nums[j]) * (long long)(end - j + 1);
                dq.pop_front();
            }
            dq.push_front(l);

            // shrink the right end until cost <= k
            while (cost > k) {
                cost -= (long long)nums[dq.back()] - nums[R];
                if (dq.back() == R) dq.pop_back();
                R--;
            }
            ans += R - l + 1;
        }
        return ans;
    }
};