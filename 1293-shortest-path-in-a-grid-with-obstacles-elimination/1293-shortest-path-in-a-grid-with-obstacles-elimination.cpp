class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m, -1));
        queue<pair<pair<int, int>, int>>q;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int steps = 0;

        q.push({{0, 0}, k});
        vis[0][0] = k;

        while(q.size() != 0){
            int states = q.size();
            for(int i = 0; i<states; i++){
                auto it = q.front();
                q.pop();

                int row = it.first.first;
                int col = it.first.second;
                int remaining = it.second;

                if(row == n-1 && col == m-1){
                    return steps;
                }

                for(int d = 0; d < 4; d++){
                    int x = row + dx[d];
                    int y = col + dy[d];

                    if(x < 0 || y < 0 || x >= n || y >= m){
                        continue;
                    }

                    int nextRemaining = remaining - grid[x][y];

                    if(nextRemaining < 0){
                        continue;
                    }

                    if(vis[x][y] < nextRemaining){
                        vis[x][y] = nextRemaining;
                        q.push({{x, y}, nextRemaining});
                    }
                }

            }
            steps++;
        }

        return -1;
    }
};