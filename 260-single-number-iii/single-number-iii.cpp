class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr=0;
        for(int n:nums){
            xorr^=n;
        }
        xorr=(xorr&(xorr-1))^xorr;
        int xorr1=0;
        int xorr2=0;
        for(int n:nums){
            if(n&xorr)xorr1^=n;
            else xorr2^=n;
        }
        return {xorr1,xorr2};
    }
};