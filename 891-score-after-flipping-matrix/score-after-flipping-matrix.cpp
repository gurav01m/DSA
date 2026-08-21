class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            if(grid[i][0]==0){
                for(int j=0;j<col;j++){
                    grid[i][j]=!grid[i][j];
                }
            }
        }
        int ans=0;
        for(int j=0;j<col;j++){
            int ones=0;
            for(int i=0;i<row;i++){
                ones+=grid[i][j];
            }
            int best=max(ones,row-ones);
            ans+=best<<(col-j-1);
        }
        return ans;
    }
};