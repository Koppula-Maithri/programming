class Solution {
public:
int f(int n,vector<int>&dp){
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i%3]=dp[(i-1)%3]+dp[(i-2)%3];
    }
    return dp[n%3];
}
    int climbStairs(int n) {
        vector<int>dp(3);
      return f(n,dp);
    }
};