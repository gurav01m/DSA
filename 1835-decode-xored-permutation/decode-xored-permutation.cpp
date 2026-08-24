class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        vector<int>ans;
        int n=encoded.size();
        int xor_enc=0;
        for(int i=0;i<encoded.size();i+=2){
            xor_enc^=encoded[i];
        }
        int xor_full=0;
        if((n+1)%4==0)xor_full=n+1;
        else if((n+1)%4==1)xor_full=1;
        else if((n+1)%4==2)xor_full=n+2;
        int ele=xor_full^xor_enc;
        ans.push_back(ele);
        for(int i=n-1;i>=0;i--){
            ele=ele^encoded[i];
            ans.push_back(ele);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};