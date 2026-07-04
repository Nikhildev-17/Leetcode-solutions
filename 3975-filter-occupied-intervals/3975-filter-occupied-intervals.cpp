class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& intervals , int freeStart, int freeEnd) {
        sort(intervals.begin(), intervals.end());
        vector<int>curr = intervals[0];
        
        vector<vector<int>>merged;
        for(int i = 1; i<intervals.size(); i++){
            
            if(intervals[i][0] <= curr[1] + 1){
                curr[1] = max(curr[1], intervals[i][1]);
            }else{
                merged.push_back(curr);
                curr = intervals[i];
            }
        }

        merged.push_back(curr);

        vector<vector<int>> ans;

        for(auto &interval : merged){

            int l = interval[0];
            int r = interval[1];
        
            if(r < freeStart || l > freeEnd){
                ans.push_back({l, r});
            }
            else{
                if(l < freeStart){
                    ans.push_back({l, freeStart - 1});
                }
                if(r > freeEnd){
                    ans.push_back({freeEnd + 1, r});
                }
            }
        }

        return ans;
        
    }
};