class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>edges = {
            {0,1},
            {0,-1},
            {1,0},
            {-1, 0}
        };
        vector<vector<int>>indegree(n, vector<int>(m, 0));
        queue<pair<int, int>>q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                for(auto it : edges){
                    int x = i + it[0];
                    int y = j + it[1];

                    if(x < 0 || x >= n || y < 0 || y >= n){
                        continue;
                    }
                    if(matrix[x][y] < matrix[i][j]){
                        indegree[i][j]++;
                    }
                }
                if(indegree[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        int ans = 0;

        while(!q.empty()){
            int k = q.size();
            for(int c = 0; c<k; c++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(auto it : edges){
                    int x = i + it[0];
                    int y = j + it[1];

                    if(x < 0 || x >= n || y < 0 || y >=m){
                        continue;
                    }
                    if(matrix[x][y] > matrix[i][j]){
                        indegree[x][y]--;
                        if(indegree[x][y] == 0){
                            q.push({x, y});
                        }
                    }
                }
            }
            ans++;
        }

        return ans;

    }
};