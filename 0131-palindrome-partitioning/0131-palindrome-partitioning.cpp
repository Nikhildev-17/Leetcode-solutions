class Solution {
public:
    bool isPalindrome(string s1){
        string temp = s1;
        reverse(temp.begin(), temp.end());
        return temp == s1;
    }

    void palindromePartition(vector<vector<string>>& ans, vector<string>& currAns, string currString, string s, int idx){
        if(idx == s.length()){
            ans.push_back(currAns);
            return;
        }
        for(int i=idx; i<s.length(); i++){
            if(isPalindrome(s.substr(idx, i - idx + 1))){
                currString = s.substr(idx, i - idx + 1);
                currAns.push_back(currString);
                palindromePartition(ans, currAns, currString, s, i + 1);
                currAns.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> currAns;
        string currString = "";
        palindromePartition(ans, currAns, currString, s, 0);

        return ans;
    }
};