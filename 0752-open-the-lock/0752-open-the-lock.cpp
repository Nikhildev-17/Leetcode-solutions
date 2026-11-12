class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        if(target == "0000"){
            return 0;
        }
        
        unordered_set<string>s;
        for(int i = 0; i<deadends.size(); i++){
            s.insert(deadends[i]);
        }

        queue<pair<string, int>>q;
        unordered_set<string>vis;
        q.push({"0000", 0});
        vis.insert("0000");
        while(!q.empty()){
            string str = q.front().first;
            int turns = q.front().second;
            q.pop();
            if(s.find(str) != s.end()){
                continue;
            }
            for(int i = 0; i<4; i++){
                char temp = str[i];
                int digit = str[i] - '0';
                int next = (digit + 1) % 10;
                int prev = (digit + 9) % 10;

                str[i] = next + '0';
                if(str == target){
                    return turns + 1;
                }
                if(vis.find(str) == vis.end()){
                    vis.insert(str);
                    q.push({str, turns+1});
                }
                
                str[i] = prev + '0';
                if(str == target){
                    return turns + 1;
                }
                if(vis.find(str) == vis.end()){
                    vis.insert(str);
                    q.push({str, turns+1});
                }
                
                str[i] = temp;
            }
        }

        return -1;
    }
};