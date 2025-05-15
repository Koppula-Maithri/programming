class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>arr(numCourses);
        vector<int>indegree(numCourses,0);
       for (auto& pre : prerequisites) {
            arr[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            cnt++;
            for(auto it:arr[curr]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(cnt==numCourses){
            return true;
        }
        else{
            return false;
        }
    }
};