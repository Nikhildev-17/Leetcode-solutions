class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();
        int st = 0;
        int end = n - 1;

        vector<int> v(2, -1);

        while(st <= end){
            int mid = st + (end - st)/2;

            if(nums[mid] > target){
                end = mid - 1;
            }
            else if(nums[mid] < target){
                st = mid + 1;
            }
            else{
                v[0] = mid;
                end = mid - 1;
            }
        }

        st = 0;
        end = n - 1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(nums[mid] > target){
                end = mid - 1;
            }
            else if(nums[mid] < target){
                st = mid + 1;
            }
            else{
                v[1] = mid;
                st = mid + 1;
            }
        }

        return v;
    }
};