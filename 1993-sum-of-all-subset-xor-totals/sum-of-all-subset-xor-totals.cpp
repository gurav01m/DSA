class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int subsets=1<<n;
        int ans=0;
        for(int i=0;i<subsets;i++){
            int sums=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j))sums^=nums[j];
            }
            ans+=sums;
        }
        return ans;
    }
};