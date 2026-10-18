class Solution {
public:
    bool isValid(vector<int>& piles, int n, int h, int speed){
        
        int hours = 0;
        for(int i = 0; i<n; i++){
            
            if(piles[i] <= speed){
                hours++;
            }else{
                int time = (piles[i] + speed - 1)/speed;
                hours += time;
            }
            if(hours > h){
                return false;
            }
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal = piles[0];
        for(int i = 1; i<piles.size(); i++){
            maxVal = max(maxVal, piles[i]);
        }

        int st = 1;
        int end = maxVal;
        int mid;
        while(st <= end){
            mid = st + (end-st)/2;
            if(isValid(piles, piles.size(), h, mid)){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }

        return st;
    }
};