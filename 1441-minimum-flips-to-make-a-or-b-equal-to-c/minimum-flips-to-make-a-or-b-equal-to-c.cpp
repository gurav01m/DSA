class Solution {
public:
    int minFlips(int a, int b, int c) {
        int check=a|b;
        int cnt=0;
        check=check^c;
        for(int i=0;i<30;i++){
            if(check&(1<<i)){
                if(a&(1<<i)&&b&(1<<i))cnt+=2;
                else if( a&(1<<i))cnt+=1;
                else if (b&(1<<i))cnt+=1;
                else cnt+=1;
            }
        }
        return cnt;
        
    }
};