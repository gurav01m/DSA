class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int ans=0;
        if(n1%2==1){
            for(int k:nums2){
                ans^=k;
            }
        }
        if(n2%2==1){
            for(int k:nums1){
                ans^=k;
            }
        }
        return ans;

    }
};