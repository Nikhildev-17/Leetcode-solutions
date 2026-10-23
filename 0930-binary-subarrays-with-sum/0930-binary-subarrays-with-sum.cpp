class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int>mp;
        mp[sum]++;
        
        int count = 0;
        int prefixReq;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            
            prefixReq = sum - goal;

            if(mp.find(prefixReq) != mp.end()){
                count += mp[prefixReq];
            }
            mp[sum]++;
        }

        return count;
    }
};