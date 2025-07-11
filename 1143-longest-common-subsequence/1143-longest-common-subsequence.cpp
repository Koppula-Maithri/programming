class Solution {
public:
int f(string &s1,string &s2,int ind1,int ind2,vector<vector<int>>&dp){
    if(ind1<0||ind2<0){
        return 0;
    }
    if(dp[ind1][ind2]!=-1){
        return dp[ind1][ind2];
    }
    if(s1[ind1]==s2[ind2]){
        return dp[ind1][ind2]=1+f(s1,s2,ind1-1,ind2-1,dp);
    }
    return dp[ind1][ind2]=max(f(s1,s2,ind1-1,ind2,dp),f(s1,s2,ind1,ind2-1,dp));

}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        f(text1,text2,n-1,m-1,dp);
        return dp[n-1][m-1];
    }
};