class Solution {
public:
    bool f(int n, int k, vector<int> &arr) {
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (arr[0] <= k) {
            dp[0][arr[0]] = true;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool notTaken = dp[ind - 1][target];
                bool taken = false;
                if (arr[ind] <= target) {
                    taken = dp[ind - 1][target - arr[ind]];
                }
                dp[ind][target] = notTaken || taken;
            }
        }
        return dp[n - 1][k];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += nums[i];
        }
        if (s % 2 != 0) return false; 
        return f(n, s / 2, nums);   
    }
};
