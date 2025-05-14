class Solution {
public:
void dfs(int ro,int co,vector<vector<int>>&vis,vector<vector<char>>& board,int delr[],int delco[]){
     int n =board.size();
        int m=board[0].size();
    vis[ro][co]=1;
    for(int i=0;i<4;i++){
        int r=ro+delr[i];
        int c=co+delco[i];
        if(r>=0&&r<n&&c>=0&&c<m&&vis[r][c]!=1&&board[r][c]=='O'){
            dfs(r,c,vis,board,delr,delco);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int n =board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delr[]={-1,0,1,0};
        int delco[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && vis[i][0]!=1){
                dfs(i,0,vis,board,delr,delco);
            }
            if(board[i][m-1]=='O' && vis[i][m-1]!=1){
                 dfs(i,m-1,vis,board,delr,delco);
            }
        }
         for(int j=0;j<m;j++){
            if(board[0][j]=='O' && vis[0][j]!=1){
                dfs(0,j,vis,board,delr,delco);
            }
            if(board[n-1][j]=='O' && vis[n-1][j]!=1){
                 dfs(n-1,j,vis,board,delr,delco);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};