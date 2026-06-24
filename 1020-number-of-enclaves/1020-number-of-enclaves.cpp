class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>&vis){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return;
        }
        if(grid[i][j] != 1 || vis[i][j]){
            return;
        }
        vis[i][j] = true;
        dfs(i-1, j, m, n, grid, vis);
        dfs(i, j+1, m, n, grid, vis);
        dfs(i+1, j, m, n, grid, vis);
        dfs(i, j-1, m, n, grid, vis);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1){
                    dfs(i, j, m, n, grid, vis);
                }
            }
        }

        int ans = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    ans += 1;
                }
            }
        }

        return ans;
    }
};