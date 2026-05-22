class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty()){
            s1.push(x);
        }else{
            while(!s1.empty()){
                int top1 = s1.top();
                s1.pop();
                s2.push(top1);
            }
            s1.push(x);
            while(!s2.empty()){
                int top2 = s2.top();
                s2.pop();
                s1.push(top2);
            }
        }
    }
    
    int pop() {
        int top1 = s1.top();
        s1.pop();
        return top1;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */