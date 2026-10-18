class Solution {
public:
    int minimum(vector<int>& hand){
        int minVal = hand[0];
        for(int i = 1; i<hand.size(); i++){
            minVal = min(hand[i], minVal);
        }

        return minVal;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        while(hand.size() > 0){
            int minVal = minimum(hand);
            for(int i = 0; i<groupSize;i++){
                auto it = find(hand.begin(), hand.end(), minVal + i);
                if(it != hand.end()){
                    hand.erase(it);
                }else{
                    return false;
                }
            }
        }

        return true;
    }
};