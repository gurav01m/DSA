class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=INT_MAX;
        int ok=false;
        for(int n:nums1){
            mini=min(mini,n);
            if(n%2==1)ok=true;
        }
        if(mini%2==0&&ok)return false;
        return true;
    }
};