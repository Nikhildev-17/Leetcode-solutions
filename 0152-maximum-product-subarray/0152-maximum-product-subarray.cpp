class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];

        for(int i = 1; i<n; i++){
            int oldMax = currMax;
            int oldMin = currMin;

            currMax = max({nums[i], nums[i]*oldMax, nums[i]*oldMin});
            currMin = min({nums[i], nums[i]*oldMax, nums[i]*oldMin});

            ans = max(ans, currMax);
        }

        return ans;
    }
};