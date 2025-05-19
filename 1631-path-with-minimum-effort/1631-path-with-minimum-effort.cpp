class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
            vector<vector<int>>diff(n,vector<int>(m,1e9));
            q.push({0,{0,0}});
            diff[0][0]=0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
            while(!q.empty()){
                auto it=q.top();
                q.pop();
                int currDiff=it.first;
                int r=it.second.first;
                int c=it.second.second;
                if(r==n-1&&c==m-1){
                    return currDiff;
                }
                for(int i=0;i<4;i++){
                    int ro=dr[i]+r;
                    int co=dc[i]+c;
                    if(ro>=0&&co>=0&&ro<n&&co<m){
                        int newE=max(currDiff,abs(heights[ro][co]-heights[r][c]));
                        if(newE<diff[ro][co]){
                            diff[ro][co]=newE;
                            q.push({newE,{ro,co}});
                        }
                    }
                }
            }
            return -1;
    }
};