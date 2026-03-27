class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int greatest = 0, sum = 0;
        for(int i=0; i<gain.size(); i++){
            sum += gain[i];
            greatest = max(greatest, sum);
        }
        return greatest;
    }
};