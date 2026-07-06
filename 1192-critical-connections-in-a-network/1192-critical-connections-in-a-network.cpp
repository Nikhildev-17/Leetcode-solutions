class Solution {
public:
    void dfs(int u, int parU, int& time, vector<bool>& vis, vector<int>& dt, vector<int>& low, vector<vector<int>>& ans, vector<vector<int>>& adj){
        vis[u] = true;
        time++;
        dt[u] = time;
        low[u] = time;

        for(int v : adj[u]){
            if(! vis[v]){
                dfs(v, u, time, vis, dt, low, ans, adj);

                low[u] = min(low[u], low[v]);
                if(low[v] > dt[u]){
                    ans.push_back({u, v});
                }
            }else if(vis[v] && v != parU){
                low[u] = min(low[u], dt[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int time = 0;
        vector<bool>vis(n, false);

        vector<int>dt(n);
        vector<int>low(n);

        vector<vector<int>>ans;

        for(int i = 0; i<n; i++){
            if(! vis[i]){
                dfs(i, -1, time, vis, dt, low, ans, adj);
            }
        }
        return ans;
    }
};