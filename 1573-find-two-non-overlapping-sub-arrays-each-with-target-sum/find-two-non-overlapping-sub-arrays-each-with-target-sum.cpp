class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, 1e9);

        int left = 0;
        long long sum = 0;
        int ans = 1e9;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            if (right > 0)
                best[right] = best[right - 1];

            if (sum == target) {
                int len = right - left + 1;

                if (left > 0 && best[left - 1] != 1e9) {
                    ans = min(ans, len + best[left - 1]);
                }

                best[right] = min(best[right], len);
            }
        }

        return ans == 1e9 ? -1 : ans;
    }
};