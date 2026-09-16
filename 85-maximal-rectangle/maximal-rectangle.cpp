class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxarea = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxarea = max(maxarea, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int nse = heights.size();
            int ele = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxarea = max(maxarea, heights[ele] * (nse - pse - 1));
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxarea = 0;
        vector<vector<int>> presum(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (matrix[i][j] == '0') {
                    presum[i][j] = 0;
                } else {
                    presum[i][j] = 1 + (i > 0 ? presum[i - 1][j] : 0);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            vector<int> heights = presum[i];
            int area = largestRectangleArea(heights);
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};