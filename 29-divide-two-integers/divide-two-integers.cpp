class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans=0;
        bool sign=true;
        if(dividend<=0&&divisor>0)sign=false;
        if(dividend>0&&divisor<0)sign=false;
        long long n=abs((long long)dividend);
        long long d=abs((long long)divisor);
        while(n>=d){
            int cnt=0;
            while(n>=d<<(cnt+1)){
                cnt++;
            }
            ans+=1LL<<cnt;
            n-=d<<cnt;
        }
        if(ans>INT_MAX&&sign==true)return INT_MAX;
        if(ans>INT_MAX&&sign==false)return INT_MIN;
        if(!sign)return -ans;
        return ans;
    }
};