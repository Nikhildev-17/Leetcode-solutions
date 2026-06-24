class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>>q;

        vector<vector<int>>ans(m, vector<int>(n, 0));
        vector<vector<bool>>vis(m, vector<bool>(n, false));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 0) {
                    vis[i][j] = true;
                    q.push({i, j});
                }
                else{
                    ans[i][j] = -1;
                }
            }
        }

        int level = 0;

        while(! q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            level++;

            if(i - 1 >= 0 && ! vis[i-1][j]){  // top
                ans[i - 1][j] = ans[i][j] + 1;
                q.push({i - 1, j});
                vis[i-1][j] = true;
            }
            if(j + 1 < n && ! vis[i][j + 1]){  // left
                ans[i][j + 1] = ans[i][j] + 1;
                q.push({i, j + 1});
                vis[i][j+1] = true;
            }
            if(i + 1 < m && ! vis[i + 1][j]){  // bottom
                ans[i + 1][j] = ans[i][j] + 1;
                q.push({i + 1, j});
                vis[i+1][j] = true;
            }
            if(j - 1 >= 0 && ! vis[i][j - 1]){   //right
                ans[i][j - 1] = ans[i][j] + 1;
                q.push({i, j - 1});
                vis[i][j-1] = true;
            }
        }

        return ans;
        
    }
};