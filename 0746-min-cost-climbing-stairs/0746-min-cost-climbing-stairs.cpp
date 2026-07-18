class Solution {
public:
    int minCostClimbingStairs(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        dp[0] = nums[0];
        dp[1] = nums[1];

        for(int i = 2; i<n; i++){
            dp[i] = min(dp[i-1] + nums[i], dp[i-2] + nums[i]);
        }

        return min(dp[n-1] , dp[n-2]);
    }
};