class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<long long, vector<int>>> pq;
        for(int i = 0; i<n; i++){
            int x = points[i][0];
            int y = points[i][1];

            long long dist = (long long)x*x + (long long) y*y;

            if(pq.size() < k){
                pq.push({dist, {x, y}});
            }else if(dist < pq.top().first){
                pq.pop();
                pq.push({dist, {x, y}});
            }
        }
        vector<vector<int>>ans;
        while(pq.size() > 0){
            ans.push_back({pq.top().second[0], pq.top().second[1]});
            pq.pop();
        }

        return ans;
    }
};