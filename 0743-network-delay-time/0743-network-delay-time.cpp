class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       
        vector<vector<pair<int,int>>> adj(n + 1);

       
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }

        vector<int> distance(n + 1, 1e9);
        distance[k] = 0;

        queue<pair<int, int>> q;
        q.push({0, k});

        while (!q.empty()) {
            auto it = q.front(); 
            q.pop();

            int dist = it.first;
            int node = it.second;

            for (auto& iti : adj[node]) {
                int nextNode = iti.first;
                int weight = iti.second;

                if (dist + weight < distance[nextNode]) {
                    distance[nextNode] = dist + weight;
                    q.push({distance[nextNode], nextNode});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (distance[i] == 1e9) {
                return -1;
            }
            ans = max(ans, distance[i]);
        }

        return ans;
    }
};
