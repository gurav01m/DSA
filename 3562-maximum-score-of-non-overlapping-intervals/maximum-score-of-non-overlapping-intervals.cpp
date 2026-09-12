class Solution {
public:
    using P = pair<long long, vector<int>>;

    P better(P a, P b) {
        if (a.first != b.first)
            return (a.first > b.first ? a : b);

        return (a.second < b.second ? a : b);
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }
        sort(a.begin(), a.end());
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n;

            while (l < r) {
                int mid = l + (r - l) / 2;

                if (a[mid][0] > a[i][1])
                    r = mid;
                else
                    l = mid + 1;
            }

            nxt[i] = l;
        }
        vector<vector<P>> dp(n + 1, vector<P>(5, {0, {}}));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                P skip = dp[i + 1][k];
                P take = dp[nxt[i]][k - 1];

                take.first += a[i][2];
                take.second.push_back(a[i][3]);
                sort(take.second.begin(), take.second.end());

                dp[i][k] = better(skip, take);
            }
        }

        return dp[0][4].second;
    }
};