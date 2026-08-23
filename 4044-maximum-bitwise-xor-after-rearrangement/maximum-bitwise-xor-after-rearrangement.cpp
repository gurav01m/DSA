class Solution {
public:
    string maximumXor(string s, string t) {
        string ans="";
        int n=s.length();
        int one=0;
        int zero=0;
        for(int i=0;i<n;i++){
           if(t[i]=='1')one++;
           else zero++;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='1'&&zero){
                ans.push_back('1');
                zero--;
            }
            else if(s[i]=='0'&&one){
                ans.push_back('1');
                one--;
            }
            else if(one){
                ans.push_back('0');
                one--;
            }
            else{
                ans.push_back('0');
                zero--;
            }
        }
        return ans;
    }
};