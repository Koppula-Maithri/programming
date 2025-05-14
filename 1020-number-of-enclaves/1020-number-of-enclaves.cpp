class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 1){
                    vis[i][j]=1;
                    q.push({i,j});
                }

            }
        }
        int delro[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int ro=r+delro[i];
                int co=c+delc[i];
                if(ro>=0&&ro<n&&co>=0&&co<m&&vis[ro][co]==0&& grid[ro][co]==1){
                    vis[ro][co]=1;
                    q.push({ro,co});
                }
            }
        }
            int cnt=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1 && vis[i][j]==0){
                        cnt++;
                    }
                }
            }
            return cnt;


        
    }
};