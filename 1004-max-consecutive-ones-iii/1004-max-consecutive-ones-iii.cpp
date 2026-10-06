class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int zeroes = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();

        while(left <= right && left < n && right < n){
            
            if(nums[right] == 0){
                zeroes++;
            }

            if(zeroes > k){
                while(zeroes > k){
                    if(nums[left] == 0){
                        zeroes--;
                    }
                    left++;
                }
            }

            ans = max(ans, right-left+1);
            right++;
        }

        return ans; 
    }
};