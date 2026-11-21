class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        // children in CSR form
        vector<int> start(n + 1, 0), child(n > 1 ? n - 1 : 0);
        for (int i = 1; i < n; i++) start[parent[i] + 1]++;
        for (int i = 0; i < n; i++) start[i + 1] += start[i];
        vector<int> pos(start.begin(), start.end() - 1);
        for (int i = 1; i < n; i++) child[pos[parent[i]]++] = i;

        vector<int> last(26, -1), np(n, -1), saved(n, -1), idx(n, 0), order, stk;
        order.reserve(n);
        stk.reserve(n);

        // enter root
        int c0 = s[0] - 'a';
        saved[0] = last[c0];
        last[c0] = 0;
        order.push_back(0);
        stk.push_back(0);

        while (!stk.empty()) {
            int x = stk.back();
            if (start[x] + idx[x] < start[x + 1]) {
                int y = child[start[x] + idx[x]++];
                int c = s[y] - 'a';
                np[y] = (last[c] != -1) ? last[c] : parent[y];
                saved[y] = last[c];
                last[c] = y;
                order.push_back(y);
                stk.push_back(y);
            } else {
                stk.pop_back();
                last[s[x] - 'a'] = saved[x];
            }
        }

        vector<int> ans(n, 1);
        for (int i = n - 1; i >= 1; i--) {
            int x = order[i];
            ans[np[x]] += ans[x];
        }
        return ans;
    }
};