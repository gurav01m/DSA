class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int subsets=1<<n;
        int ans=0;
        int cnt=0;
        for(int i=1;i<subsets;i++){
            int orr=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j))orr=orr|nums[j];
            }
            if(orr>ans){
                ans=orr;
                cnt=1;
            }
            else if(orr==ans)cnt++;
        }
        return cnt;
    }
};