class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1));

        for(int i = 0; i<=amount; i++){
            dp[0][i] = INT_MAX;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=amount; j++){
                if(coins[i-1] <= j){

                    if(dp[i][j-coins[i-1]] != INT_MAX){
                        dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
                    }else{
                        dp[i][j] = min(INT_MAX, dp[i-1][j]);
                    }
                    
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }
};