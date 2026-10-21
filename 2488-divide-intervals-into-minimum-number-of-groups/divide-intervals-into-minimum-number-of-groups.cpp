class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>strt,end;
        for(auto &i:intervals){
            strt.push_back(i[0]);
            end.push_back(i[1]);
        }
        int i=0;
        int j=0;
        int cnt=0;
        int ans=0;
        sort(strt.begin(),strt.end());
        sort(end.begin(),end.end());
        while(i<strt.size()){
            if(strt[i]<=end[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            ans=max(ans,cnt);
        }
        return ans;

    }
};