class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        int i = 0;
        int j = 0;
        int currSum;
        int n = nums1.size();
        int m = nums2.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
            
        for(int i = 0; i<min(k, n); i++){
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        while(!pq.empty() && k > 0){
            auto it = pq.top();
            pq.pop();
            int firstIdx = it.second.first;
            int secondIdx = it.second.second;

            ans.push_back({nums1[firstIdx], nums2[secondIdx]});
            k--;

            if (secondIdx + 1 < m) {
                pq.push({nums1[firstIdx] + nums2[secondIdx + 1],{firstIdx, secondIdx + 1}});
            }
        }

        return ans;
    }
};