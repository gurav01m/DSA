class Solution {
public:
    void dfs(string&num,int target,int start,long long curr_val,long long last_operand,string expression,vector<string>&ans){
        if(start==num.size()){
            if(curr_val==target){
                ans.push_back(expression);
                return;
            }
        }
        for(int i=start;i<num.size();i++){
            if(i>start&&num[start]=='0')return;
            string curr_num=num.substr(start,i-start+1);
            long long curr_num_val=stoll(curr_num);
            if(start==0){
                dfs(num,target,i+1,curr_num_val,curr_num_val,curr_num,ans);
            }
            else{
                dfs(num,target,i+1,curr_val+curr_num_val,curr_num_val,expression+"+"+curr_num,ans);
                dfs(num,target,i+1,curr_val-curr_num_val,-curr_num_val,expression+"-"+curr_num,ans);
                dfs(num,target,i+1,curr_val-last_operand+last_operand*curr_num_val,last_operand*curr_num_val,expression+"*"+curr_num,ans);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        dfs(num,target,0,0,0,"",ans);
        return ans;
    }
};