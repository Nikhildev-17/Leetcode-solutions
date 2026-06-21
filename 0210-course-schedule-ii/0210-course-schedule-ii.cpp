class Solution {
public:
    bool dfs(int src, vector<vector<int>>& adj, vector<bool>& vis, stack<int>&s, vector<bool>& recPath){
        vis[src] = true;
        recPath[src] = true;

        for(int u : adj[src]){
            if(!vis[u]){
                if(dfs(u, adj, vis, s, recPath)) return true;
            }
            else if(recPath[u]) return true;
        }

        s.push(src);
        recPath[src] = false;

        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool>vis(n, false);
        vector<bool>recPath(n, false);
        stack<int>s;

        for(int i=0; i<edges.size(); i++){
            int u = edges[i][1];
            int v = edges[i][0];

            adj[u].push_back(v);
        }

        for(int j = 0; j<adj.size(); j++){
            if(!vis[j]){
                if(dfs(j, adj, vis, s, recPath)) return {};
            }
        }

        vector<int>ans;
        while(!s.empty()){
            int top = s.top();
            ans.push_back(top);
            s.pop();
        }

        return ans;
    }
};