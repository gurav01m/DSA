class Solution {
public:
    void solve(int sum,int k,int last,vector<vector<int>>&ans,vector<int>&nums){
        if(sum==0&& nums.size()==k){
            ans.push_back(nums);
        }
        if(sum<=0 || nums.size()>k)return;
        for(int i=last;i<=9;i++){
            if(i<=sum){
                nums.push_back(i);
                solve(sum-i,k,i+1,ans,nums);
                nums.pop_back();
            }
            else{
                break;
            }
        }
    } 
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>nums;
        solve(n,k,1,ans,nums);
        return ans;
    }
};