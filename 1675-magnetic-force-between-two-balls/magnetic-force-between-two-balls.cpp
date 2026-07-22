class Solution {
public:
    bool canplace(vector<int>&position,int mid,int m){
        int cnt=1;
        int last=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last>=mid){
                cnt++;
                last=position[i];
            }
        }
        return cnt>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=1;
        int high=position.back()-position.front();
        int ans=0;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(canplace(position,mid,m)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }

        }
        return ans;

    }
};