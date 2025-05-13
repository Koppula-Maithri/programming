class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
         vector<vector<int>>dis(n,vector<int>(m,0));
         queue<pair<pair<int,int>,int>>q;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
         }
         int delr[]={-1,0,1,0};
         int delc[]={0,1,0,-1};
         while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int s=q.front().second;
            q.pop();
            dis[r][c]=s;
            for(int i=0;i<4;i++){
                int ro=r+delr[i];
                int co=c+delc[i];
                if(ro>=0&&ro<n&&co<m&&co>=0&&vis[ro][co]==0){
                    vis[ro][co]=1;
                    q.push({{ro,co},s+1});
                }
            }
         }
         return dis;

    }
};