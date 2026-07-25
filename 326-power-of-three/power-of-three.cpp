class Solution {
public:
    bool isPowerOfThree(int n) {
       long long ans=1162261467;
       if(n<=0)return false;
       if(ans%n==0)return true;
       return false; 
    }
};