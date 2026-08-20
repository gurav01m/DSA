class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        int ele=1<<n;
        for(int i=0;i<ele;i++){
            if(i&(i<<1)){
                continue;
            }
            string s="";
            int cost=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    s.push_back('1');
                    cost+=j;
                }
                else{
                    s.push_back('0');
                }
            }
            if(cost<=k)ans.push_back(s);
        }
        return ans;
    }
};