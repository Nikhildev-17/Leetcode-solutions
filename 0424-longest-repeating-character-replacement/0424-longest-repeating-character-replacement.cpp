class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int right = 0;
        vector<int>freq(26, 0);
        int maxFreq = 0;
        int ans = 0;

        while(left <= right && right < n){
            freq[s[right] - 'A']++;

            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            if((right - left + 1) - maxFreq > k){
                freq[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};