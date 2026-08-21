class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]^arr[i];
        }
        vector<int>ans;
        for(auto&it:queries){
            int p=it[0];
            int q=it[1];
            ans.push_back(prefix[p]^prefix[q+1]);
        }
        return ans;
    }
};