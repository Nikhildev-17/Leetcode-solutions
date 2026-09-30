class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1));

        for(int i = 0; i<=n; i++){
            dp[i][0] = 0;
        }

        for(int i = 0; i<=m; i++){
            dp[0][i] = 0;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int i = n;
        int j = m;
        string lcs = "";
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                lcs += str1[i-1];
                i--;
                j--;
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                    i--;
                }else{
                    j--;
                }
            }
        }

        reverse(lcs.begin(), lcs.end());

        i = 0;
        j = 0; 
        int k = 0;
        string ans = "";

        while(k < lcs.size()){
            while(i < n && str1[i] != lcs[k]){
                ans += str1[i];
                i++;
            }

            while(j < m && str2[j] != lcs[k]){
                ans += str2[j];
                j++;
            }

            ans += lcs[k];
            i++;
            j++;
            k++;
        }

        while(i < n){
                ans += str1[i];
                i++;
            }

        while(j < m){
            ans += str2[j];
            j++;
        }
    return ans;
    }
};