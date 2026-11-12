class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>>neighbours = {
            {-1, 0},
            {0, -1},
            {+1, 0},
            {0, +1}
        };
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>>q;
        q.push({{entrance[0], entrance[1]}, 0});
        vis[entrance[0]][entrance[1]] = true;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            for(auto it : neighbours){
                int x = i + it[0];
                int y = j + it[1];

                if(x < 0 || x >= n || y < 0 || y >= m){
                    continue;
                }

                if(maze[x][y] != '+' && vis[x][y] == false){
                    if((x == 0 || x == n-1 || y == 0 || y == m-1) && maze[x][y] == '.'){
                        return dist + 1;
                    }
                    q.push({{x, y}, dist + 1});
                    vis[x][y] = true;
                }
                
            }
        }

        return -1;
    }
};