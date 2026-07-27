class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>curr(10,0);
        for(int n:digits){
            curr[n]++;
        }
        vector<int>ans;
        int res=0;
        for(int i=100;i<=998;i+=2){
            int a=i%10;
            int b=(i/10)%10;
            int c=i/100;
            vector<int>need(10,0);
            need[a]++;
            need[b]++;
            need[c]++;
            bool ok=true;
            for(int i=0;i<10;i++){
                if(need[i]>curr[i]){
                    ok=false;
                    break;
                }
            }
            if(ok)res++;

        }
        
        return res;

    }
};