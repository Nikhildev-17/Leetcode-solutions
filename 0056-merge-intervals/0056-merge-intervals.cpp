class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prevLast = intervals[0][1];
        int prevFirst = intervals[0][0];
        vector<vector<int>>ans;

        for(int i = 1; i<intervals.size(); i++){
            int currFirst = intervals[i][0];
            int currLast = intervals[i][1];
            
            if(currFirst <= prevLast){
                prevLast = max(currLast, prevLast);
            }else{
                ans.push_back({prevFirst, prevLast});
                prevFirst = currFirst;
                prevLast = currLast;
            }
        }

        ans.push_back({prevFirst, prevLast});

        return ans;
    }
};