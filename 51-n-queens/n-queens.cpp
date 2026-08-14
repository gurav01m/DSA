class Solution {
public:
    bool issafe(int rows,int col,vector<string>&board,int n){
        int drows=rows;
        int dcol=col;
        while(rows>=0&&col>=0){
            if(board[rows][col]=='Q')return false;
            rows--;
            col--;
        }
        rows=drows;
        col=dcol;
        while(col>=0&&rows<n){
            if(board[rows][col]=='Q')return false;
            col--;
            rows++;
        }
        rows=drows;
        col=dcol;
        while(col>=0){
            if(board[rows][col]=='Q')return false;
            col--;
        }
        return true;
    }
    void solve(int col,int n,vector<vector<string>>&ans,vector<string>&board){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int rows=0;rows<n;rows++){
            if(issafe(rows,col,board,n)){
                board[rows][col]='Q';
                solve(col+1,n,ans,board);
                board[rows][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,n,ans,board);
        return ans;
    }
};