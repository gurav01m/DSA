class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>freqA(n+1,0);
        vector<int>freqB(n+1,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            freqA[A[i]]++;
            freqB[B[i]]++;
            if(freqA[A[i]]==1 &&freqB[A[i]]==1)cnt++;
            if(freqA[B[i]]==1 &&freqB[B[i]]==1)cnt++;
            if(A[i]==B[i])cnt--;
            A[i]=cnt;
        }
        return A;
        
    }
};