class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto node:roads){
            adj[node[0]].push_back({node[1],node[2]});
            adj[node[1]].push_back({node[0],node[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        int mod=1e9+7;
        vector<long long>distance(n,1e9);
        vector<int>ways(n,0);
        distance[0]=0;
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long dis=it.first;
            int node=it.second;
            for(auto iti:adj[node]){
                int adjNode=iti.first;
                long long d=iti.second;
                if(dis+d<distance[adjNode]){
                    distance[adjNode]=dis+d;
                    ways[adjNode]=ways[node];
                    pq.push({dis+d,adjNode});
                }
                else if(dis+d==distance[adjNode]){
                    ways[adjNode]=(ways[node]+ways[adjNode])%mod;
                }
            }
        }
        return ways[n-1];
    }
};