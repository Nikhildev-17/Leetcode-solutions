class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, int> mp;
        vector<int>freq(26);
        string s;
        vector<vector<string>>ans;
        int idx = 0;
        for(int i = 0; i<strs.size(); i++){
            for(int i = 0; i<26; i++){
                freq[i] = 0;
            }
            s = strs[i];
            for(char ch : s){
                freq[ch - 'a']++;
            }
            
            if(mp.find(freq) == mp.end()){
                ans.push_back({s});
                mp[freq] = idx;
                idx++;
            }else{
                ans[mp[freq]].push_back(s);
            }
            
        }

        return ans;
    }
};