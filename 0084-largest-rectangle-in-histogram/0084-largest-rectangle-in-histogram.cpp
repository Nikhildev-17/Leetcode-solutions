class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> prevSmaller(n);
        stack<int> prevSt;

        for(int i=0; i<n; i++){
            while(!prevSt.empty() && heights[prevSt.top()] >= heights[i]){
                prevSt.pop();
            }
            if(prevSt.empty()){
                prevSmaller[i] = -1;
            }else{
                prevSmaller[i] = prevSt.top();
            }
            prevSt.push(i);
        }

        vector<int> nextSmaller(n);
        stack<int> nextSt;

        for(int i = n-1; i>=0; i--){
            while(!nextSt.empty() && heights[nextSt.top()] >= heights[i]){
                nextSt.pop();
            }
            if(nextSt.empty()){
                nextSmaller[i] = n;
            }else{
                nextSmaller[i] = nextSt.top();
            }
            nextSt.push(i);
        }

        int ans = 0;
        int currArea;
        for(int i=0; i<n; i++){
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            currArea = heights[i] * width;
            ans = max(ans, currArea);
        }
        
        return ans;
    }
};