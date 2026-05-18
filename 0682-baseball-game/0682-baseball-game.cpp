class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string ope : operations){
            if(ope == "C"){
                st.pop();
            }
            else if(ope == "D"){
                st.push(st.top() * 2);
            }else if(ope == "+"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.push(first);

                st.push(first + second);
            }else{
                st.push(stoi(ope));
            }
        }
        int sum = 0;

        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        
        return sum;
    }
};