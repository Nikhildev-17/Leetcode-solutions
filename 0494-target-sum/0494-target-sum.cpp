class Solution {
public:
    int helper(vector<int>& nums, int target, int i, int n, int minTarget, vector<vector<int>>& dp){
        int index = target - minTarget;
        if(i == n){
            return target == 0;
        }
        if(dp[i][index] != -1){
            return dp[i][index];
        }
        int ans1 = helper(nums, target + nums[i], i+1, n, minTarget, dp);
        int ans2 = helper(nums, target - nums[i], i+1, n, minTarget, dp);

        return dp[i][index] = ans1 + ans2;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        int minTarget = target - sum;
        int width = 2 * sum + 1;
        vector<vector<int>>dp(n, vector<int>(width, -1));

        return helper(nums, target, 0, n, minTarget, dp);
    }
};