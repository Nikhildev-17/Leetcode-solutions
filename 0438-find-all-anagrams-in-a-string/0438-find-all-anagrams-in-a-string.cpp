class Solution {
public:
    bool isEqual(int freq[], int windowFreq[]){
        for(int i=0; i<26; i++){
            if(freq[i] != windowFreq[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        vector<int> ans;
        int windowLength = p.length();
        if(windowLength > n){
            return {};
        }
        
        int freq[26] = {0};
        int windowFreq[26] = {0};

        for(int i=0; i<windowLength; i++){
            windowFreq[s[i] - 'a']++;
        }

        for(char x : p){
            freq[x - 'a']++;
        }

        if(isEqual(freq, windowFreq)){
            ans.push_back(0);
        }

        for(int i=windowLength; i<n; i++){
            windowFreq[s[i] - 'a']++;
            windowFreq[s[i - windowLength] - 'a']--;

            if(isEqual(freq, windowFreq)){
                ans.push_back(i-windowLength + 1);
            }
        }

        return ans;
    }
};