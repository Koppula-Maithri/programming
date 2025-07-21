class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            int st=intervals[i][0];
            int end=intervals[i][1];
            if(ans.empty()||ans.back()[1]<st){
                ans.push_back({st,end});
            }
            else{
                ans.back()[1]=max(ans.back()[1],end);
            }
        }
        return ans;
        
    }
};