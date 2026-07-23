class Solution {
public:
    int helper(vector<int>& nums, int d){
        int n = nums.size();
        int ansCount = 0;
        int j = 0;
        for(int i = 0; i<n; i++){
            while(j < n && nums[j] - nums[i] <= d){
                j++;
            }
            ansCount += j-i-1;
        }

        return ansCount;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int minDist = INT_MAX;
        for(int i = 0; i<n-1; i++){
            minDist = min(minDist, nums[i+1] - nums[i]);
        }
        int maxDist = nums[n-1]-nums[0];
        int st = minDist;
        int end = maxDist;
        while(st < end){
            int mid = st + (end-st)/2;
            int count = helper(nums, mid);
            if(count >= k){
                end = mid;
            }else{
                st = mid + 1;
            }
        }

        return st;
    }
};