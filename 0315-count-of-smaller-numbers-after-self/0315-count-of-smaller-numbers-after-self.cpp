class Solution {
public:

    void merge(vector<pair<int,int>>& arr, int st, int mid, int end, vector<int>& ans){

        int j = mid + 1;


        for(int i = st; i <= mid; i++){

            while(j <= end && arr[i].first > arr[j].first){
                j++;
            }

            ans[arr[i].second] += (j - (mid + 1));
        }


        vector<pair<int,int>> temp;

        int left = st;
        int right = mid + 1;

        while(left <= mid && right <= end){

            if(arr[left].first <= arr[right].first){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }

        while(right <= end){
            temp.push_back(arr[right]);
            right++;
        }


        for(int i = 0; i < temp.size(); i++){
            arr[st + i] = temp[i];
        }
    }

    void mergeSort(vector<pair<int,int>>& arr, int st, int end, vector<int>& ans){

        if(st >= end){
            return;
        }

        int mid = st + (end - st) / 2;

        mergeSort(arr, st, mid, ans);

        mergeSort(arr, mid + 1, end, ans);

        merge(arr, st, mid, end, ans);
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        vector<pair<int,int>> arr;

        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }

        vector<int> ans(n, 0);

        mergeSort(arr, 0, n - 1, ans);

        return ans;
    }
};