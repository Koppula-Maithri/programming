class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjL, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adjL[node]) {
            if (!vis[it]) {
                dfs(it, adjL, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjL(n);   
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjL[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);  
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adjL, vis);
            }
        }

        return cnt;
    }
};
