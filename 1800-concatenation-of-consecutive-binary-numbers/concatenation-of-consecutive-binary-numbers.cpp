class Solution {
public:
    int concatenatedBinary(int n) {
        long long M=1000000000+7;
        int digit=0;
        long long ans=0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0)digit++;
            ans=((ans<<digit)^i)%M;
        }
        return ans;
    }
};