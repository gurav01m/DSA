class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int low = 0;
        int high = price.back() - price.front();
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            int cnt = 1;
            int last = price[0];
            for (int i = 1; i < price.size(); i++) {
                if (price[i] - last >= mid) {
                    cnt++;
                    last = price[i];
                }
            }
            if (cnt >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};