class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>> q;
        int cntf = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1){
                    cntf++;
                }
            }
        }

        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        int tmax = 0;
        int cnt = 0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            tmax = max(t, tmax);

            for(int i = 0; i < 4; i++){
                int ro = r + row[i];
                int co = c + col[i];
                if(ro >= 0 && ro < n && co >= 0 && co < m && vis[ro][co] == 0 && grid[ro][co] == 1){
                    q.push({{ro, co}, t + 1});
                    vis[ro][co] = 2;
                    cnt++;
                }
            }
        }

        if(cnt != cntf){
            return -1;
        }
        else{
            return tmax;
        }
    }
};
