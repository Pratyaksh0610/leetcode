class MedianFinder {
public:
priority_queue<int>small;
priority_queue<int,vector<int>,greater<int>>big;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.size()<=big.size()){
            small.push(num);
        }
        else{
            big.push(num);
        }
        if(small.size()&&big.size()&&small.top()>big.top()){
            int t1=small.top(),t2=big.top();
            small.pop(),big.pop();
            small.push(t2),big.push(t1);
        }
    }
    
    double findMedian() {
        if((small.size()+big.size())%2!=0){
            return small.top();
        }
        // cout<<small.top()<<" "<<big.top()<<endl;
        return ((double)(small.top()+big.top()))/(double)2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */