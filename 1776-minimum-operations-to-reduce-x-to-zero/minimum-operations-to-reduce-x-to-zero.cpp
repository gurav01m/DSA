class Solution {
public:
    int minOperations(vector<int>& nums,int x) {
        int n=nums.size();
        int total=0;
        for(int a:nums) total+=a;

        int target=total-x;
        if(target<0) return -1;
        if(target==0) return n;

        int l=0,sum=0,maxLen=-1;

        for(int r=0;r<n;r++){
            sum+=nums[r];

            while(sum>target){
                sum-=nums[l];
                l++;
            }

            if(sum==target)
                maxLen=max(maxLen,r-l+1);
        }

        return maxLen==-1?-1:n-maxLen;
    }
};