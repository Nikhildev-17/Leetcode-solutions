class MedianFinder {
public:
    priority_queue<int>pq1;
    priority_queue<int, vector<int>, greater<int>>pq2;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.size() == 0 && pq2.size() == 0){
            pq1.push(num);
            return;
        }
        if(num > pq1.top()){
            pq2.push(num);
        }else{
            pq1.push(num);
        }
        if(abs((int)pq1.size() - (int)pq2.size()) >= 2){
            if(pq1.size() > pq2.size()){
                int topVal = pq1.top();
                pq1.pop();
                pq2.push(topVal);
            }else{
                int topVal = pq2.top();
                pq2.pop();
                pq1.push(topVal);
            }
        }   
    }
    
    double findMedian() {
        if(pq1.size() == pq2.size()){
            return (double)(pq1.top() + pq2.top()) / 2;
        }
        if(pq1.size() > pq2.size()){
            return (double)pq1.top();
        }else{
            return (double)pq2.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */