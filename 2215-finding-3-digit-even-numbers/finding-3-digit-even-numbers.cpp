class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int>mpp;
        for(int n:digits){
            mpp[n]++;
        }
        vector<int>ans;
        for(int i=100;i<=998;i+=2){
            int a=i%10;
            int b=(i/10)%10;
            int c=i/100;

            unordered_map<int,int>need;
            need[a]++;
            need[b]++;
            need[c]++;
            bool ok=true;
            for(auto &p:need){
                if(mpp[p.first]<p.second){
                    ok=false;
                    break;
                }
            }
            if(ok){
                ans.push_back(i);
            }
        }
        return ans;
    }
};