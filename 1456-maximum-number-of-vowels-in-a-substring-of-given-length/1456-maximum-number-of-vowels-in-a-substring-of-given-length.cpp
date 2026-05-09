class Solution {
public:
    bool isVowel(char x){
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        int vowelCount = 0;
        for(int i=0; i<k; i++){
            if(isVowel(s[i])){
                vowelCount++;
            }
        }
        int maxVowelCount = vowelCount;

        for(int i=k; i<n; i++){
            if(isVowel(s[i])){
                vowelCount++;
            }
            if(isVowel(s[i - k])){
                vowelCount--;
            }

            maxVowelCount = max(maxVowelCount, vowelCount);
        }

        return maxVowelCount;
    }
};