class Solution {
public:
    void solve(vector<string>&ans,int index,string &s,string &k){
        if(s.length()<=k.length()){
            ans.push_back(k);
            return;
        }
        if(isdigit(s[index])){
            k.push_back(s[index]);
            solve(ans,index+1,s,k);
            k.pop_back();
        }
        else{
            k.push_back(tolower(s[index]));
            solve(ans,index+1,s,k);
            k.pop_back();
            k.push_back(toupper(s[index]));
            solve(ans,index+1,s,k);
            k.pop_back();
        }

    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        int index=0;
        string k="";
        solve(ans,index,s,k);
        return ans;
    }
};