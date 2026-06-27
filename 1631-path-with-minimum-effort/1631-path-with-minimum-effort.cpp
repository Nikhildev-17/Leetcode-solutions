class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& height) {
        int n = height.size();
        int m = height[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> >pq;               //{diff, {i, j}}
        vector<vector<int>>efforts(n, vector<int>(m, INT_MAX));
        efforts[0][0] = 0;

        pq.push({0,{0, 0}});
        int maxDiff = 0;

        while(! pq.empty()){
            int heightDiff = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if(heightDiff > efforts[i][j]) continue;

            if(i == n-1 && j == m-1)
                return heightDiff;

            if(i-1 >= 0){
                int diff = abs(height[i][j] - height[i-1][j]);  //up
                maxDiff = max(diff, heightDiff);
                if(maxDiff < efforts[i-1][j]){
                    efforts[i-1][j] = maxDiff;
                    pq.push({maxDiff, {i-1, j}});
                }
            }
            if(j+1 < m){
                int diff = abs(height[i][j] - height[i][j+1]);
                maxDiff = max(diff, heightDiff);
                if(maxDiff < efforts[i][j+1]){
                    efforts[i][j+1] = maxDiff;
                    pq.push({maxDiff, {i, j+1}});
                }
            }
            if(i+1 <n){
                int diff = abs(height[i][j] - height[i+1][j]);
                maxDiff = max(diff, heightDiff);
                if(maxDiff < efforts[i+1][j]){
                    efforts[i+1][j] = maxDiff;
                    pq.push({maxDiff, {i+1, j}});
                }
            }
            if(j - 1 >= 0){
                int diff = abs(height[i][j] - height[i][j-1]);
                maxDiff = max(diff, heightDiff);
                if(maxDiff < efforts[i][j-1]){
                    efforts[i][j-1] = maxDiff;
                    pq.push({maxDiff, {i, j-1}});
                }
            }
        }

        return 0;
    }
};