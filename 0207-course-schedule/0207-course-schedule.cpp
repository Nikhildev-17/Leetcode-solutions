class Solution {
public:
    bool isCycle(int src, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& recPath){
        vis[src] = true;
        recPath[src] = true;

        for(int i : adj[src]){
            if(!vis[i]){
                if(isCycle(i, adj, vis, recPath)) return true;
            }else if(recPath[i]){
                return true;
            }
        }

        recPath[src] = false; 
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& edges) {

        vector<bool>vis(n, false);
        vector<bool> recPath(n, false);

        vector<vector<int>>adj(n);

        for(int i = 0; i<edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            adj[u].push_back(v);
        }

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                if(isCycle(i, adj, vis, recPath))return false;;
            }
        }

        return true;
    }
};