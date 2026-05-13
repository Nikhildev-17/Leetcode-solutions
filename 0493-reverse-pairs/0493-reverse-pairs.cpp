class Solution {
public:
    int merge(vector<int>& nums, int st, int end, int mid){
        int i = st; 
        int j = mid + 1;
        int Count = 0;
        vector<int> temp;
        while(i <= mid && j <= end){
            if(nums[i] <= 2LL * nums[j]){
                i++;
            }else{
                j++;
                Count += mid-i+1;
            }
        }
        i = st; 
        j = mid + 1;
        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= end){
            temp.push_back(nums[j]);
            j++;
        }

        for(int idx = 0; idx< temp.size(); idx++){
            nums[idx + st] = temp[idx];
        }

        return Count;
    }
    int mergeSort(vector<int>& nums, int st, int end){
        if(st < end){
            int mid = st + (end-st)/2;
            int leftCount = mergeSort(nums, st, mid);
            int rightCount = mergeSort(nums, mid + 1, end);

            int count = merge(nums, st, end, mid);

            return leftCount + rightCount + count;
        }
        return 0;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int st = 0; 
        int end = n-1;
        
        return mergeSort(nums, st, end);
    }
};