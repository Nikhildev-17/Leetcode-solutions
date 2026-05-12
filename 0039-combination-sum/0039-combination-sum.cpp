class Solution {
public:
    void solve(vector<int>& candidates, vector<int>& currPath, vector<vector<int>>& ans, int idx, int target){
        if(target == 0){
            ans.push_back(currPath);
            return;
        }
        if(target < 0){
            return;
       }

       for(int i=idx; i< candidates.size(); i++){
            currPath.push_back(candidates[i]);
            solve(candidates, currPath, ans, i, target - candidates[i]);
            currPath.pop_back();
       }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currPath;
        vector<vector<int>> ans;
        solve(candidates, currPath, ans, 0, target);

        return ans;
    }
};