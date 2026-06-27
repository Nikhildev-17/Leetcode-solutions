class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 0});


        vector<bool>vis(points.size(), false);

        int minCost = 0;

        while(! pq.empty()){
            int dist = pq.top().first;
            int index = pq.top().second;
            pq.pop();

            if(! vis[index]){
                vis[index] = true;
                minCost += dist;
                for(int i=0; i<points.size(); i++){
                    if(i == index)continue;
                    int xi = points[index][0];
                    int yi = points[index][1];
                    int xj = points[i][0];
                    int yj = points[i][1];
                    int wt = abs(xi-xj) + abs(yi-yj);

                    pq.push({wt, i});
                }
            }
        }

        return minCost;
    }
};