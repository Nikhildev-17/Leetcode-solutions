class Solution {
public:
    int dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& grid, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != 1){

            return 0;
        }

        vis[i][j] = true;

        int topArea = dfs(i - 1, j, vis, grid, n, m);
        int rightArea = dfs(i, j + 1, vis, grid, n, m);
        int bottomArea = dfs(i + 1, j, vis, grid, n, m);
        int leftArea = dfs(i, j - 1, vis, grid, n, m);
        
        return topArea + rightArea + bottomArea + leftArea + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int maxArea = 0;
        for(int i=0; i<n; i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int currArea = dfs(i, j, vis, grid, n, m);
                    maxArea = max(maxArea, currArea);
                }
            }
        }

        return maxArea;
    }
};