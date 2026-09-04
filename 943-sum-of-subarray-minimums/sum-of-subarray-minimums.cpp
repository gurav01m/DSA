class Solution {
public:
    vector<int>findnse(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>findpse(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse=findnse(arr);
        vector<int>pse=findpse(arr);
        long long m=1e9+7;
        long long total=0;
        for(int i=0;i<arr.size();i++){
            long long l=i-pse[i];
            long long r=nse[i]-i;
            total=(total+(r*l*arr[i])%m)%m;
        }
        return total;
        
    }
};