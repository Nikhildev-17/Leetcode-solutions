class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>indegree(n);

        vector<vector<int>> revGrid(n);

        for(int i = 0; i<n; i++){
            for(int j : grid[i]){
                revGrid[j].push_back(i);
            }
        }

        for(int i = 0; i<n; i++){
            for(int j : grid[i]){
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i = 0; i<indegree.size(); i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int>ans;

        while(! q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for(int j : revGrid[top]){
                indegree[j]--;
                if(indegree[j] == 0) q.push(j);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};