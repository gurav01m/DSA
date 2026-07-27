class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            string t="";
            for(char c:s){
                t+= (c == 'z') ? 'a' : char(c + 1);
            }
            s+=t;
        }
        return s[k-1];
    }
};