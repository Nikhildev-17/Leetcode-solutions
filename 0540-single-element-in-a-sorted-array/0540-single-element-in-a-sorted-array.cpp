class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int end = n-1;

        while(st < end){
            int mid = st + (end - st)/2;

            mid = mid - (mid % 2);

            if(nums[mid] == nums[mid + 1]){
                st = mid + 2;
            }else if(nums[mid] != nums[mid + 1]){
                end = mid;
            }
        }

        return nums[st];
    }
};