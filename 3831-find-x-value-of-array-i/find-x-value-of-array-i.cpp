class Solution {
public:
    vector<long long> resultArray(vector<int>& nums,int k) {
        vector<long long> ans(k,0),dp(k,0);

        for(int x:nums){
            vector<long long> ndp(k,0);
            int a=x%k;

            ndp[a]++;

            for(int r=0;r<k;r++){
                if(dp[r]){
                    ndp[(r*a)%k]+=dp[r];
                }
            }

            dp=ndp;

            for(int r=0;r<k;r++){
                ans[r]+=dp[r];
            }
        }

        return ans;
    }
};