class Solution {
public:
    int search(vector<int>& nums, int target) {
         int n = nums.size(), k = 0;

        // Find rotation index
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                k = i + 1;
                break;
            }
        }

        int st = 0, end = n - 1;

                if(target == nums[0]) return 0;
        if(target == nums[n - 1]) return n - 1;

        if(k == 0) {
            st = 0;
            end = n - 1;
        }
        else if(target >= nums[0]) {
            st = 0;
            end = k - 1;
        } else {
            st = k;
            end = n - 1;
        }

        while(st <= end) {
            int mid = st + (end - st) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                st = mid + 1;
            else
                end = mid - 1;
        }

        return -1;
    }

};