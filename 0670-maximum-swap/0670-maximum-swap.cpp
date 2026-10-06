class Solution {
public:
    int maximumSwap(int num) {
        if(num == 0) return 0;
        int temp = num;
        vector<int>arr;
        int n = 0;
        while(temp > 0){
            arr.push_back(temp % 10);
            temp = temp/10;
            n++;
        }
        reverse(arr.begin(), arr.end());
        

        vector<int>right(n-1);

        for(int i = 0; i<n-1; i++){
            int maxDigit = -1;
            int maxIndex = -1;
            for(int j = i+1; j<n; j++){
                if(arr[j] >= maxDigit){
                    maxDigit = arr[j];
                    maxIndex = j;
                }
            }
            right[i] = maxIndex;
        }
        right.push_back(-1);

        for(int i = 0; i<right.size(); i++){
            if(right[i] != -1 && arr[i] < arr[right[i]]){
                swap(arr[i], arr[right[i]]);
                break;
            }
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = ans * 10 + arr[i];
        }

        return ans;
    }
};