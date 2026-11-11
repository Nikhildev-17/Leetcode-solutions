class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s;

        for(int i = 0; i<wordList.size(); i++){
            s.insert(wordList[i]);
        }

        queue<pair<string, int>>q;
        q.push({beginWord, 1});

        while(!q.empty()){
            string str = q.front().first;
            int ans = q.front().second;
            q.pop();
            for(int i = 0; i<str.size(); i++){
                char ch = str[i];
                for(int j = 0; j<26; j++){
                    str[i] = 'a' + j;
                    if(s.find(str) != s.end()){
                        if(str == endWord){
                            return ans+1;
                        }

                        q.push({str, ans+1});
                        s.erase(str);
                    }
                }
                str[i] = ch;
            }
        }

        return 0;
    }
};