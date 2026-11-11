class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1){
            return -1;
        }
        if(n == 1 && grid[0][0] == 0){
            return 1;
        }
        vector<pair<int, int>>edges = {
            {0, -1}, //top
            {+1, 0}, //right
            {0, +1}, //bottom
            {-1, 0}, //left
            {+1, -1},
            {1, 1},
            {-1, +1},
            {-1, -1}
        };
        queue<pair<pair<int, int>, int>>q;
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        q.push({{0,0},1});

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            for(auto it : edges){
                int x = i + it.first;
                int y = j + it.second;
                if(x >= n || y >= n || x < 0 || y < 0){
                    continue;
                }
                if(grid[x][y] != 1 && !vis[x][y]){
                    q.push({{x, y}, dist+1});
                    vis[x][y] = true;
                    if(x == n-1 && y == n-1){
                        return dist + 1;
                    }
                }
            }
        }
        return -1;
    }
};