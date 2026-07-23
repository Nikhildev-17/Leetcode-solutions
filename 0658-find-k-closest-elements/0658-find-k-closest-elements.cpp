class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int>ans;
        int low = 0;
        int high = n-k;
        
        while(low < high){

            int mid = low + (high-low)/2;

            if(x - arr[mid] > arr[mid+k] - x)
                low = mid+1;
            else
                high = mid;
        }

        for(int i = low; i<=low + k-1; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};