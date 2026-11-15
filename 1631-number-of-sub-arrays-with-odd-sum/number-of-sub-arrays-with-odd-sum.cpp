class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long evenCnt = 1, oddCnt = 0, ans = 0;
        int parity = 0;
        for (int x : arr) {
            parity ^= (x & 1);
            if (parity) {
                ans += evenCnt;
                oddCnt++;
            } else {
                ans += oddCnt;
                evenCnt++;
            }
            ans %= MOD;
        }
        return ans;
    }
};