class Solution {
public:
    void solve(string &digits,int index,vector<string>&ans,string &output,string mapping[]){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        int value=digits[index]-'0';
        string texts=mapping[value];
        for(int i=0;i<texts.length();i++){
            output.push_back(texts[i]);
            solve(digits,index+1,ans,output,mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output="";
        int index=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.length()==0)return ans;
        solve(digits,index,ans,output,mapping);
        return ans;
    }
};