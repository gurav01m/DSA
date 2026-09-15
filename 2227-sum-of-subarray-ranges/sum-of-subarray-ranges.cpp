class Solution {
public:
    vector<int>fnse(vector<int>& nums){
        int n=nums.size();
        stack<int>st;
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>=nums[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>fpse(vector<int>& nums){
        int n=nums.size();
        stack<int>st;
        vector<int>pse(n);
        for(int i=0;i<=n-1;i++){
            while(!st.empty()&&nums[st.top()]>nums[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int>fnge(vector<int>& nums){
        int n=nums.size();
        stack<int>st;
        vector<int>nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]<=nums[i]){
                st.pop();
            }
            nge[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int>fpge(vector<int>& nums){
        int n=nums.size();
        stack<int>st;
        vector<int>pge(n);
        for(int i=0;i<=n-1;i++){
            while(!st.empty()&&nums[st.top()]<nums[i]){
                st.pop();
            }
            pge[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pge;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>nse=fnse(nums);
        vector<int>pse=fpse(nums);
        vector<int>nge=fnge(nums);
        vector<int>pge=fpge(nums);
        long long t=0;
        for(int i=0;i<nums.size();i++){
            long long l1=i-pse[i];
            long long l2=i-pge[i];
            long long r1=nse[i]-i;
            long long r2=nge[i]-i;
            t+=-1*(l1*r1*nums[i])+(l2*r2*nums[i]);
        }
        return t;

    }
};