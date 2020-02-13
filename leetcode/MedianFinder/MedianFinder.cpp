class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int> > bigNums;
    priority_queue<int> smallNums;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(smallNums.empty() || num<=smallNums.top())
        {
            smallNums.push(num);
        }
        else
        {
            bigNums.push(num);
        }

        int lenSmall=smallNums.size(),
            lenBig=bigNums.size();
        if(lenSmall<lenBig)
        {
            smallNums.push(bigNums.top());
            bigNums.pop();
        }
        else if(lenSmall>lenBig+1)
        {
            bigNums.push(smallNums.top());
            smallNums.pop();
        }
    }

    double findMedian() {
        if(smallNums.size()==bigNums.size())
        {
            return (smallNums.top()+bigNums.top())/2.0;
        }
        else
        {
            return smallNums.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */