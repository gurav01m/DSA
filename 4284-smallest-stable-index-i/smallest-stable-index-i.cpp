class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans=-1;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            int mini=nums[i];
            for(int j=i;j<nums.size();j++){
                mini=min(nums[j],mini);
            }
            if(maxi-mini<=k){
                return i;
            }
        }
        return ans;
    }
};