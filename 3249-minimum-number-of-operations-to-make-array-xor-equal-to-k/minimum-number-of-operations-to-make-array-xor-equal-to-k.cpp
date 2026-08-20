class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorr=0;
        for(int n:nums){
            xorr^=n;
        }
        xorr=xorr^k;
        int cnt=0;
        while(xorr!=0){
            xorr=xorr&(xorr-1);
            cnt++;
        }
        return cnt;
    }
};