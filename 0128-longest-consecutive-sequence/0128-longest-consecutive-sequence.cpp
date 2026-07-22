class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int n = nums.size();
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        
        int maxLen = 0;
        for(int x : st){
            int currLen = 1;
            int currEle = x;

            if(st.count(currEle-1)){
                continue;
            }
            while(true){
                if(st.count(currEle + 1)){
                    currLen += 1;
                    currEle++;
                }else{
                    break;
                }
            }
            maxLen = max(maxLen, currLen);
        }
        
        return maxLen;
    }
};