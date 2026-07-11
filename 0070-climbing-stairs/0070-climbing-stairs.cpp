class Solution {
public:

    int waysToClimbStairs(int n, vector<int>& dp){
        if(n == 0 || n == 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = waysToClimbStairs(n-1, dp) + waysToClimbStairs(n-2, dp);

    }

    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return waysToClimbStairs(n, dp);
    }
};