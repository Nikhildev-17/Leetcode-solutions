class Solution {
public:
    void getCombs(string& digits, vector<string>& mp, string& storeAns, vector<string>& ans, int idx){
        
        if(idx == digits.length()){
            ans.push_back(storeAns);
            return;
        }

        int num = digits[idx] - '0';
        string letters = mp[num];
        for(char ch : letters){
            storeAns += ch;
            getCombs(digits, mp, storeAns, ans, idx + 1);
            storeAns.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }

        vector<string> ans;
        string storeAns = "";
        vector<string> mp = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        getCombs(digits, mp, storeAns, ans, 0);

        return ans;
    }
};