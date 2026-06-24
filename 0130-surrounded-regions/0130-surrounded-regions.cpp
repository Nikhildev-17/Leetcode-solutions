class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<char>>& board, vector<vector<bool>>&vis){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return;
        }
        if(board[i][j] != 'O' || vis[i][j]){
            return;
        }
        vis[i][j] = true;
        dfs(i-1, j, m, n, board, vis);
        dfs(i, j+1, m, n, board, vis);
        dfs(i+1, j, m, n, board, vis);
        dfs(i, j-1, m, n, board, vis);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O'){
                    dfs(i, j, m, n, board, vis);
                }
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                    vis[i][j] = true;
                }
            }
        }


    }
};