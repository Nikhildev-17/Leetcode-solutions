class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        vector<vector<pair<int, int>>>adj(n+1);

        for(int i = 0; i<times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({v, wt});
        }

        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while(! pq.empty()){
            int u = pq.top().second;
            int distU = pq.top().first;
            pq.pop();

            if(distU > dist[u]) continue;

            for(auto neighbours : adj[u]){
                int v = neighbours.first;
                int wt = neighbours.second;

                

                if(dist[v] > distU + wt){
                    dist[v] = distU + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        for(int i = 1; i<n+1; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
        }

        int timeTaken = dist[1];
        for(int i = 2; i<n+1; i++){
            if(dist[i] > timeTaken){
                timeTaken = dist[i];
            }
        }

        return timeTaken;
    }
};