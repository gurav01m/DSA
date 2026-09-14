class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroid) {
        vector<int>st;
        int n=asteroid.size();
        for(int i=0;i<n;i++){
            if(asteroid[i]>0)st.push_back(asteroid[i]);
            else{
                while(!st.empty()&&st.back()>0&&st.back()<abs(asteroid[i])){
                    st.pop_back();
                }
                if(!st.empty()&&st.back()==abs(asteroid[i])){
                    st.pop_back();
                }
                else if(st.empty()||st.back()<0){
                    st.push_back(asteroid[i]);
                }
            }
        }
        return st;
    }
};