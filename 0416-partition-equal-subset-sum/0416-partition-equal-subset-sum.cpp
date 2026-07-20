class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0; i<n; i++){
            totalSum += nums[i];
        }

        if(totalSum % 2 != 0) return false;
        int target = totalSum / 2;

        vector<vector<int>>dp(n+1, vector<int>(target + 1));
        for(int i = 0; i<=n; i++){
            dp[i][0] = 0;
        }

        for(int j = 0; j<=target; j++){
            dp[0][j] = 0;
        }

        for(int i = 1; i<= n; i++){
            for(int j = 1; j<= target; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = max(dp[i-1][j-nums[i-1]] + nums[i-1], dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][target] == target;
    }
};