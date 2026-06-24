class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        queue<pair<int, int>>q;

        vector<vector<int>>height(m, vector<int>(n, -1));

        for(int i = 0; i<m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 1){
                    q.push({i, j});
                    height[i][j] = 0;
                }
            }
        }


        while(! q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if(i > 0 && height[i-1][j] == -1){
                height[i-1][j] = height[i][j] + 1;
                q.push({i-1, j});
            }
            if(j < n-1 && height[i][j+1] == -1){
                height[i][j+1] = height[i][j] + 1;
                q.push({i, j+1});
            }
            if(i < m-1 && height[i+1][j] == -1){
                height[i+1][j] = height[i][j] + 1;
                q.push({i+1, j});
            }
            if(j > 0 && height[i][j-1] == -1){
                height[i][j-1] = height[i][j] + 1;
                q.push({i, j-1});
            }
        }

        return height;
    }
};