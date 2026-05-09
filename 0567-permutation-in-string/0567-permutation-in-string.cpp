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
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        int freq[26] = {0};
        int windowFreq[26] = {0};

        for(char x : s1){
            freq[x - 'a']++;
        }

        int window = s1.length();

        for(int i=0; i<window; i++){
            windowFreq[s2[i] - 'a']++;
        }

        if(isEqual(freq, windowFreq)){
            return true;
        }

        for(int i = window; i<s2.length(); i++){
            windowFreq[s2[i] - 'a']++;
            windowFreq[s2[i-window]-'a']--;

            if(isEqual(freq, windowFreq)){
                return true;
            }
        }
        return false;
    }
};