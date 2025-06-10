class Solution {
public:
vector<int> f(int row){
    vector<int>rans;
    rans.push_back(1);
    int ans=1;
    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans=ans/col;
        rans.push_back(ans);
    }
    return rans;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(f(i));
        }
        return ans;
    }
};