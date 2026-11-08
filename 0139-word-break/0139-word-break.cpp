class Solution {
public:
    bool helper(string s, vector<string>& wordDict, int st, unordered_set<string>& dict, vector<int>& calc){

        if(st == s.size()){
            return true;
        }
        if(calc[st] != -1){
            return calc[st];
        }

        for(int i = st; i<s.size(); i++){
            string str = s.substr(st, i-st+1);

            if(dict.find(str) != dict.end()){
                if(helper(s, wordDict, i+1, dict, calc)){
                    calc[st] = 1;
                    return true;
                }
            }
        }

        return calc[st] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(), wordDict.end());
        vector<int>calc(s.size(), -1);
        
        return helper(s, wordDict, 0, dict, calc);
    }
};