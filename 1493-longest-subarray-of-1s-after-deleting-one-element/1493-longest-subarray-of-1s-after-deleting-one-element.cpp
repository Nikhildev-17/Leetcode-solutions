class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int right = 0;
        int left = 0;
        int zeroes = 0;
        int n = nums.size();
        while(left <= right && left < n && right < n){
            if(nums[right] == 0){
                zeroes++;
            }
            if(zeroes > 1){
                while(zeroes > 1){
                    if(nums[left] == 0){
                        zeroes--;
                    }
                    left++;
                }
            }

            ans = max(ans, right - left);
            right++;
        }

        return ans;
    }
};