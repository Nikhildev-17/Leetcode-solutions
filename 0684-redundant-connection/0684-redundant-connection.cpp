class Solution {
public:
    int find(int a, vector<int>& par){
        if(par[a] == a){
            return a;
        }
        return par[a] = find(par[a], par);
    }

    void unionBySet(int a, int b, vector<int>& par, vector<int>& rank){
        int parA = find(a, par);
        int parB = find(b, par);

        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        }else if(rank[parA] > rank[parB]){
            par[parB] = parA;
        }else{
            par[parA] = parB;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>par(n+1);
        vector<int>rank(n + 1);

        for(int i = 1; i<=n; i++){
            par[i] = i;
            rank[i] = 0;
        }

        for(int i = 0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            if(find(a, par) == find(b, par)){
                return {a, b};
            }
            unionBySet(a, b, par, rank);
        }

        return {};

    }
};