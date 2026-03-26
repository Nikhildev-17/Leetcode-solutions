class Solution {
public:
    void subsets(vector<int>& nums, int i, vector<vector<int>>& solution, vector<int>& ans){
        if(i == nums.size()){
            solution.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        subsets(nums, i + 1, solution, ans);

        ans.pop_back();
        int idx = i + 1;
        while(idx < nums.size() && nums[idx] == nums[idx - 1]){
            idx ++;
        }
        subsets(nums, idx, solution, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> solution;
        vector<int>ans;

        sort(nums.begin(), nums.end());

        subsets(nums, 0, solution, ans);
        return solution;
    }
};