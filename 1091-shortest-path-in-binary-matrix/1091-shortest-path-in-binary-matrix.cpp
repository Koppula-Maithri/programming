class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        if (n == 1 && grid[0][0] == 0) return 1;
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }

        q.push({1, {0, 0}});
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 1;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dist = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int delrow = -1; delrow <= 1; delrow++){
                for(int delcol = -1; delcol <= 1; delcol++){
                    int ro = r + delrow;
                    int co = c + delcol;  

                    if(ro >= 0 && co >= 0 && ro < n && co < m &&
                       grid[ro][co] == 0 && 1 + dist < dis[ro][co]){
                        dis[ro][co] = 1 + dist;

                        if(ro == n - 1 && co == n - 1){
                            return dist + 1;
                        }

                        q.push({1 + dist, {ro, co}});
                    }
                }
            }
        }

        return -1;
    }
};
