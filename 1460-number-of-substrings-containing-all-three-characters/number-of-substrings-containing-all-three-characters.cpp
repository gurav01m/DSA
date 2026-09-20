class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        vector<int>lastSeen(3,-1);
        for(int i=0;i<s.length();i++){
            lastSeen[s[i]-'a']=i;
            cnt+=1+min(lastSeen[0],min(lastSeen[1],lastSeen[2]));
        }
        return cnt;
    }
};