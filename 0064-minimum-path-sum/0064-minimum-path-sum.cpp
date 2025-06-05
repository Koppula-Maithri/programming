class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0){
                    dp[i][j]=grid[0][0];
                    continue;
                }
                int up=1e9,right=1e9;
                if(j>0){
                     right=dp[i][j-1]+grid[i][j];
                }
                if(i>0){
                     up=dp[i-1][j]+grid[i][j];
                }
                dp[i][j]=min(right,up);
            }
        }
        return dp[n-1][m-1];
    }
};