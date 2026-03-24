class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set <int> s1(nums1.begin(), nums1.end());
        vector<int> ans;
        int n = nums2.size();
        for(int i = 0; i<n; i++){
            if(s1.find(nums2[i]) != s1.end()){
                ans.push_back(nums2[i]);
                s1.erase(nums2[i]);
            }
        }
        return ans;
    }
};