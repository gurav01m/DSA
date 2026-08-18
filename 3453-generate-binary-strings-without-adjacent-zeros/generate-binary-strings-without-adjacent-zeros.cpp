class Solution {
public:
    vector<string> ans;
    void solve(int n, string& s) {
        if (s.length() == n) {
            ans.push_back(s);
            return;
        }
        s.push_back('1');
        solve(n, s);
        s.pop_back();

        if (s.empty() || s.back() != '0') {
            s.push_back('0');
            solve(n, s);
            s.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        string s;
        solve(n, s);
        return ans;
    }
};