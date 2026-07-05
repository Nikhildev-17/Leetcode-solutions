class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        queue<pair<int, pair<int, int>>> q;  // src, weight, currStops;
        q.push({src, {0, -1}});

        vector<int>dist(n, INT_MAX);
        dist[src] = 0;

        while(! q.empty()){
            int u = q.front().first;
            int currWt = q.front().second.first;
            int currStops = q.front().second.second;
            q.pop();

            for(auto V : adj[u]){
                int dest = V.first;
                int wt = V.second;

                if(dist[V.first] > currWt + wt && currStops + 1 <= k){
                    dist[V.first] = currWt + wt;
                    q.push({dest, {dist[V.first], currStops + 1}});
                }
            }
        }

        if(dist[dst] == INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};