class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0; i<asteroids.size(); i++){
            int curr = asteroids[i];
            bool currFail = false;

            if(st.empty()){
                st.push(curr);
                continue;
            }
            
            if((st.top() > 0 && curr > 0) || st.top() < 0){
                st.push(curr);
                continue;
            }

            while(!st.empty() && st.top() > 0 && curr < 0){ 
                if(abs(curr) > st.top()){
                    st.pop();
                }else if(abs(curr) == st.top()){
                    st.pop();
                    currFail = true;
                    break;
                }else{
                    currFail = true;
                    break;
                }
            }

            if(!currFail) st.push(curr);
        }
        vector<int> ans;

            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }

            reverse(ans.begin(), ans.end());

            return ans;
    }
};