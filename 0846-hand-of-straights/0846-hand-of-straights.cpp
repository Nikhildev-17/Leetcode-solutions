class Solution {
public:
    
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int>mp;
        for(int i = 0; i<hand.size(); i++){
            mp[hand[i]]++;
        }

        for(auto it : mp){
            int freq = it.second;
            int key = it.first;
            
            if(freq == 0) continue;
            if(freq < 0){
                return false;
            }
            
            for(int i = 0; i<groupSize; i++){
                if(mp.find(key + i) != mp.end()){
                    mp[key + i] -= freq;
                }else{
                    return false;
                }
            }
        }

        return true;
    }
};