class Solution {
public:
    int maxArea(vector<int>& height) {
        int st = 0, end = height.size()-1;
        int maxVol = 0;
        while(st<end){
            maxVol = max(maxVol, (end-st)*min(height[st], height[end]));
            if(height[end]>height[st])
            st++;
            else
            end--;

        }
        return maxVol;
    }
};