class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
         int m=grid[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
         queue<pair<pair<int,int>,int>>q;
         int cnt=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1){
                    cnt++;
                }
            }
         }
         int ro[]={-1,0,1,0};
         int co[]={0,1,0,-1};
         int cntf=0;
         int maxt=0;
         while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
             maxt=max(t,maxt);
            for(int i=0;i<4;i++){
                int nr=r+ro[i];
                int nc=c+co[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&grid[nr][nc]==1&&!vis[nr][nc]){
                    cntf++;
                    vis[nr][nc]=2;
                    q.push({{nr,nc},t+1});
                }
            }
         }
         if(cntf==cnt){
            return maxt;
         }
         else{
            return -1;
         }

    }
};