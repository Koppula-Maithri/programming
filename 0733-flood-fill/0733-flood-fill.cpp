class Solution {
public:
void dfs(int row,int col,int delr[],int delc[],vector<vector<int>>&ans,vector<vector<int>>&image,int color,int inico){
    int n=image.size();
    int m=image[0].size();    
    ans[row][col]=color;
    for(int i=0;i<4;i++){
          int ro = row + delr[i];
                int co = col + delc[i];
                if(ro >= 0 && ro < n && co >= 0 && co < m && image[ro][co] == inico && ans[ro][co] != color){
                    dfs(ro,co,delr,delc,ans,image,color,inico);
                }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniCo=image[sr][sc];
        vector<vector<int>>ans=image;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        dfs(sr,sc,delr,delc,ans,image,color,iniCo);
        return ans;
        
    }
};