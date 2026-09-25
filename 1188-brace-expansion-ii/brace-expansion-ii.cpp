class Solution {
public:
    vector<string> combine(vector<string>& a, vector<string>& b) {
        set<string> res;

        for (auto &x : a) {
            for (auto &y : b) {
                res.insert(x + y);
            }
        }

        return vector<string>(res.begin(), res.end());
    }

    set<string> dfs(string &s, int &i) {
        set<string> result;
        vector<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                // Union current into result
                for (auto &x : current)
                    result.insert(x);

                current = {""};
                i++;
            }

            else if (s[i] == '{') {
                i++; // skip {

                set<string> inside = dfs(s, i);

                i++; // skip }

                vector<string> temp(inside.begin(), inside.end());

                // concatenate current × inside
                vector<string> next;

                for (auto &x : current) {
                    for (auto &y : temp) {
                        next.push_back(x + y);
                    }
                }

                current = next;
            }

            else {
                // lowercase letter
                char c = s[i];
                i++;

                for (auto &x : current)
                    x += c;
            }
        }

        // Add last segment
        for (auto &x : current)
            result.insert(x);

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ansSet = dfs(expression, i);

        vector<string> ans(ansSet.begin(), ansSet.end());

        return ans;
    }
};